
void __cdecl _check(char *param_1)

{
  size_t sVar1;
  char local_11;
  uint local_10;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_10 = 0;
  while( true ) {
    sVar1 = _strlen(param_1); //sVar1： 密码长度
    if (sVar1 <= local_10) break;
    local_11 = param_1[local_10]; //local_11: 密码的第<指针>位
    _sscanf(&local_11,"%d",&local_8);
    local_c = local_c + local_8;
    if (local_c == 0x10) {
      _parell(param_1);
    }
    local_10 = local_10 + 1;
  }
  _printf("Password Incorrect!\n");
  return;
}


void __cdecl _parell(char *param_1)

{
  uint local_8;
  
  _sscanf(param_1,"%d",&local_8);
  if ((local_8 & 1) == 0) {
    _printf("Password OK!\n");
                      /* WARNING: Subroutine does not return */
    _exit(0);
  }
  return;
}