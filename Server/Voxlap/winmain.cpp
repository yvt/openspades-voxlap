/***************************************************************************************************
WINMAIN.CPP & SYSMAIN.H

Windows layer code written by Ken Silverman (http://advsys.net/ken) (1997-2009)
Additional modifications by Tom Dobrowolski (http://ged.ax.pl/~tomkh)
You may use this code for non-commercial purposes as long as credit is maintained.
***************************************************************************************************/

// This file has been modified from Ken Silverman's original release
// (It's a really significant modification. In fact, the only public function remaining here is "getcputype".)

//======================== CPU detection code begins ========================

#ifdef __WATCOMC__

long testflag (long);
#pragma aux testflag =\
    "pushfd"\
    "pop eax"\
    "mov ebx, eax"\
    "xor eax, ecx"\
    "push eax"\
    "popfd"\
    "pushfd"\
    "pop eax"\
    "xor eax, ebx"\
    "mov eax, 1"\
    "jne menostinx"\
    "xor eax, eax"\
    "menostinx:"\
    parm nomemory [ecx]\
    modify exact [eax ebx]\
    value [eax]

void cpuid (long, long *);
#pragma aux cpuid =\
    ".586"\
    "cpuid"\
    "mov dword ptr [esi], eax"\
    "mov dword ptr [esi+4], ebx"\
    "mov dword ptr [esi+8], ecx"\
    "mov dword ptr [esi+12], edx"\
    parm [eax][esi]\
    modify exact [eax ebx ecx edx]\
    value

#endif
#ifdef _MSC_VER

#pragma warning(disable:4799) //I know how to use EMMS

static _inline long testflag (long c)
{
    _asm
    {
        mov ecx, c
        pushfd
        pop eax
        mov edx, eax
        xor eax, ecx
        push eax
        popfd
        pushfd
        pop eax
        xor eax, edx
        mov eax, 1
        jne menostinx
        xor eax, eax
        menostinx:
    }
}

static _inline void cpuid (long a, long *s)
{
    _asm
    {
        push ebx
        push esi
        mov eax, a
        cpuid
        mov esi, s
        mov dword ptr [esi+0], eax
        mov dword ptr [esi+4], ebx
        mov dword ptr [esi+8], ecx
        mov dword ptr [esi+12], edx
        pop esi
        pop ebx
    }
}

#endif

#ifdef __GNUC__
static inline long testflag (long c)
{
    long a;
    __asm__ __volatile__ (
        "pushf\npopl %%eax\nmovl %%eax, %%ebx\nxorl %%ecx, %%eax\npushl %%eax\n"
        "popf\npushf\npopl %%eax\nxorl %%ebx, %%eax\nmovl $1, %%eax\njne 0f\n"
        "xorl %%eax, %%eax\n0:"
        : "=a" (a) : "c" (c) : "ebx","cc" );
    return a;
}

static inline void cpuid (long a, long *s)
{
    __asm__ __volatile__ (
        "cpuid\nmovl %%eax, (%%esi)\nmovl %%ebx, 4(%%esi)\n"
        "movl %%ecx, 8(%%esi)\nmovl %%edx, 12(%%esi)"
        : "+a" (a) : "S" (s) : "ebx","ecx","edx","memory","cc");
}
#endif

    //Bit numbers of return value:
    //0:FPU, 4:RDTSC, 15:CMOV, 22:MMX+, 23:MMX, 25:SSE, 26:SSE2, 30:3DNow!+, 31:3DNow!
long getcputype ()
{
    long i, cpb[4], cpid[4];
    if (!testflag(0x200000)) return(0);
    cpuid(0,cpid); if (!cpid[0]) return(0);
    cpuid(1,cpb); i = (cpb[3]&~((1<<22)|(1<<30)|(1<<31)));
    cpuid(0x80000000,cpb);
    if (((unsigned long)cpb[0]) > 0x80000000)
    {
        cpuid(0x80000001,cpb);
        i |= (cpb[3]&(1<<31));
        if (!((cpid[1]^0x68747541)|(cpid[3]^0x69746e65)|(cpid[2]^0x444d4163))) //AuthenticAMD
            i |= (cpb[3]&((1<<22)|(1<<30)));
    }
    if (i&(1<<25)) i |= (1<<22); //SSE implies MMX+ support
    return(i);
}
