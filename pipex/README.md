# access 함수
> 파일 권한 체크 함수 </br>
> #include <unistd.h> </br>
> int access(const char *pathname, int mode) </br>

모드 옵션 </br>
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

모드 옵션
  O_RDONRY : 읽기 전용 </br>
  
  O_WRONRY : 쓰기 전용 </br>
  
  O_RDWR : 읽기 쓰기 모두 </br>
  
  O_CREAT : open하려는 함수가 없으면 생성함, 짝궁으로 권한 값을 같이 줘야됨 </br>
  
 >위 3개는 open 함수 쓸때 기본적으로 사용되는 옵션 </br>
 >이후 아래 옵션들은 필요에 따라 사용됨, </br>
 >
  O_EXCL : O_CREAT를 사용했을 때 파일이 이미 열려있어도 열기가 가능, 쓰기를 하면 이전 내용이 사라짐, </br> O_CREAT를 O_EXCL과 함께 사용하면 open 취소,</br>
  
  O_TRUNC : 기존 파일의 내용을 모두 삭제 </br>
  
  O_APPEND : 파일을 추가하여 쓰기가 되도록 open 후에 쓰기 포인터가 파일의 끝에 위치하게 됩니다. </br>
  
  O_NOCITTY : 열기 대상이 터미널일 경우, 이 터미널이 프로그램의 제어 터미널에 해당하지 않습니다. </br>
  
  O_NONBLOCK : 읽을 내용이 없을 때에는 읽을 내용이 있을 때까지 기다리지 않고, 바로 복귀합니다. </br>
  
  O_SYNC : 쓰기를 할 때 실제 쓰기가 완료될 떄까지 기다립니다. 즉 물리적으로 쓰기가 완료되어야 복귀가 됩니다. </br>
  

