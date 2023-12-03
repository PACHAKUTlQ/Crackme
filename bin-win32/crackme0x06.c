int __cdecl main(int argc, const char **argv, const char **envp)
{
  void *v3; // esp
  char v5[120]; // [esp+20h] [ebp-78h] BYREF

  v3 = alloca(16);
  __main();
  printf("IOLI Crackme Level 0x06\n");
  printf("Password: ");
  scanf("%s", v5);
  check(v5, (int)envp);
  return 0;
}

int __cdecl check(char *Str, int a2)
{
  char Buffer; // [esp+1Bh] [ebp-Dh] BYREF
  size_t i; // [esp+1Ch] [ebp-Ch]
  int v5; // [esp+20h] [ebp-8h]
  int v6; // [esp+24h] [ebp-4h] BYREF

  v5 = 0;
  for ( i = 0; i < strlen(Str); ++i )
  {
    Buffer = Str[i];
    sscanf(&Buffer, "%d", &v6);
    v5 += v6;
    if ( v5 == 16 )
      parell(Str, a2);
  }
  return printf("Password Incorrect!\n");
}

int __main()
{
  int result; // eax

  result = initialized;
  if ( !initialized )
  {
    initialized = 1;
    return __do_global_ctors();
  }
  return result;
}

int *__cdecl parell(char *Buffer, int a2)
{
  int *result; // eax
  int i; // [esp+10h] [ebp-8h] BYREF
  int v4; // [esp+14h] [ebp-4h] BYREF

  sscanf(Buffer, "%d", &v4);
  result = (int *)dummy(v4, a2);
  if ( result )
  {
    for ( i = 0; i <= 9; ++i )
    {
      if ( (v4 & 1) == 0 )
      {
        printf("Password OK!\n");
        exit(0);
      }
      result = &i;
    }
  }
  return result;
}

int __cdecl dummy(int a1, int a2)
{
  int v2; // ecx
  int v5; // [esp+14h] [ebp-4h]

  v5 = 0;
  while ( *(_DWORD *)(4 * v5 + a2) )
  {
    v2 = 4 * v5++;
    if ( !strncmp(*(const char **)(v2 + a2), "LOLO", 3u) )
      return 1;
  }
  return 0;
}