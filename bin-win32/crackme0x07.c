void __cdecl __noreturn sub_4014D9(int a1, int a2, int a3)
{
  char v3[120]; // [esp+20h] [ebp-78h] BYREF

  sub_402E20();
  sub_401620();
  printf("IOLI Crackme Level 0x07\n");
  printf("Password: ");
  scanf("%s", v3);
  sub_401415(v3, a3);
}

int *__cdecl sub_40139E(char *Buffer, int a2)
{
  int *result; // eax
  int i; // [esp+10h] [ebp-8h] BYREF
  int v4; // [esp+14h] [ebp-4h] BYREF

  sscanf(Buffer, "%d", &v4);
  result = (int *)sub_401310(v4, a2);
  if ( result )
  {
    for ( i = 0; i <= 9; ++i )
    {
      if ( (v4 & 1) == 0 )
      {
        if ( dword_406030 == 1 )
          printf("Password OK!\n");
        exit(0);
      }
      result = &i;
    }
  }
  return result;
}
int __cdecl sub_401310(int a1, int a2)
{
  int v2; // ecx
  int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  while ( *(_DWORD *)(4 * v5 + a2) )
  {
    v2 = 4 * v5++;
    if ( !strncmp(*(const char **)(v2 + a2), "LOLO", 3u) )
    {
      dword_406030 = 1;
      return 1;
    }
  }
  return 0;
}

void __noreturn sub_401380()
{
  printf("Password Incorrect!\n");
  exit(0);
}

void __noreturn sub_401140()
{
  char *ptr; // edx
  char ***v1; // eax
  char v2[4]; // [esp+1Ch] [ebp-Ch] BYREF
  int v3; // [esp+20h] [ebp-8h] BYREF

  SetUnhandledExceptionFilter(TopLevelExceptionFilter);
  sub_401580();
  v3 = 0;
  _getmainargs(&dword_406004, &dword_406000, v2, dword_404000, &v3);
  if ( Mode )
  {
    dword_404010 = Mode;
    ptr = iob[0]._ptr;
    if ( iob[0]._ptr )
    {
      setmode(iob[0]._file, Mode);
      ptr = iob[0]._ptr;
    }
    if ( ptr != (char *)-32 )
    {
      setmode(iob[1]._file, Mode);
      ptr = iob[0]._ptr;
    }
    if ( ptr != (char *)-64 )
      setmode(iob[2]._file, Mode);
  }
  *_p__fmode() = dword_404010;
  sub_401550();
  v1 = _p__environ();
  sub_4014D9(dword_406004, dword_406000, *v1);
}

void __cdecl __noreturn sub_401415(char *Str, int a2)
{
  char Buffer; // [esp+1Bh] [ebp-Dh] BYREF
  size_t i; // [esp+1Ch] [ebp-Ch]
  int v4; // [esp+20h] [ebp-8h]
  int v5; // [esp+24h] [ebp-4h] BYREF

  v4 = 0;
  for ( i = 0; i < strlen(Str); ++i )
  {
    Buffer = Str[i];
    sscanf(&Buffer, "%d", &v5);
    v4 += v5;
    if ( v4 == 16 )
      sub_40139E(Str, a2);
  }
  sub_401380();
}

int sub_401620()
{
  int result; // eax

  result = dword_406050;
  if ( !dword_406050 )
  {
    dword_406050 = 1;
    return sub_4015C0();
  }
  return result;
}

int sub_4015C0()
{
  int j; // ebx
  int v2; // eax
  bool i; // zf

  v2 = 0;
  for ( i = sub_403010 == 0; !i; i = *(&off_403034 + v2) == 0 )
    ++v2;
  for ( j = v2; j; --j )
    ((void (*)(void))dword_403030[j])();
  return sub_4012A0((void (__cdecl *)())sub_401590);
}

int __cdecl sub_4012A0(void (__cdecl *a1)())
{
  return atexit(a1);
}

int __usercall sub_402E20@<eax>(unsigned int a1@<eax>, int a2@<ecx>, int a3)
{
  int *v3; // ecx
  int v5; // [esp-4h] [ebp-4h]
  int (__thiscall *retaddr)(int); // [esp+0h] [ebp+0h]

  v5 = a2;
  v3 = &a3;
  while ( a1 >= 0x1000 )
  {
    v3 -= 1024;
    *v3 = *v3;
    a1 -= 4096;
  }
  *(int *)((char *)v3 - a1) = *(int *)((char *)v3 - a1);
  return retaddr(v5);
}