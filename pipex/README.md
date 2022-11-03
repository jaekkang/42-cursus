# access 함수
> 파일 권한 체크 함수 </br>
> #include <unistd.h> </br>
> int access(const char *pathname, int mode)

  R_OK : 파일 존재 여부, 읽기 권한 여부 </br>
  W_OK : 파일 존재 여부, 쓰기 권한 여부 </br>
  X_OK : 파일 존재 여부, 실행 권한 여부 </br>
  F_OK : 파일 존재 여부만. </br>

  뒷 부분의 형식이 (mode의) int 이지만 비트연산 ( | )을
  통해서 여러 조건을 한번에 체크할 수 있다.
> access("test.txt", R_OK | W_OK) 처럼

# open 함수

 함수에서 외부 다른 파일을 사용할 때 사용하는 함수 </br>
파일열기에는 표준 함수인 fopen()이 있음.</br> fopen > C 표준 </br>
open() > 리눅스 제공</br>

> #include <fcntl.h> </br>
> int open (const char *FILENAME, int FLAGS[, mod_t MODE]) </br>
인수 </br>
> FILENAME : 대상 파일 이름 </br>
> FLAGS : 파일에 대한 열기 옵션 </br>
> [, mod_t MODE] O_CREATE : 옵션 사용에 의해 파일이 생성될 떄 지정되는 파일 접근 권한 </br>

> return > int 0 : 성공하면 fd값 리턴 , </br> -1 == 실패 </br>
