#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
char recv[maxn+5];
char sub[maxn+5];
int rlen, slen;
int cnt[10];
int cnt_cpy[10];

int main() {
  scanf("%s\n", recv);
  scanf("%s", sub);
  rlen = strlen(recv);

  memset(cnt, 0, sizeof cnt);

  for(int i = 0; i < rlen; i++) {
    cnt[recv[i] - '0']++;
  }
  slen = strlen(sub);
  for(int i = 0; i < slen; i++) {
    cnt[sub[i] - '0']--;
  }
  int subadd = 0;
  for(int i = 1; i < slen; i++) {
    if(sub[i] != sub[i-1]) {
      if(sub[i] < sub[i-1]) {
	subadd = -1;
      } else {
	subadd = 1;
      }
      break;
    }
  }
  int len;
  for(len = 1; len <= rlen; len++) {
    memcpy(cnt_cpy, cnt, sizeof cnt);
    int digits = len;
    bool ok = true;
    int len_cnt = 0;
    while(digits) {
      int dig = digits % 10;
      if(cnt_cpy[dig] > 0) {
	cnt_cpy[dig]--;
      } else {
	ok = false;
	break;
      }
      digits /= 10;
      len_cnt++;
    }
    if(!ok)
      continue;
    if(rlen - len_cnt != len)
      continue;
    bool zero = false;
    if(len == 1 && rlen == 2 && sub[0] == '0') {
      zero = true;
    } else if(sub[0] != '0') {
      zero = true;
    } else {
      for(int i = 1; i < 10; i++) {
	if(cnt_cpy[i] > 0) {
	  zero = true;
	  break;
	}
      }
    }
    if(zero) {
      memcpy(cnt, cnt_cpy, sizeof cnt);
      break;
    }
  }
  int write = 0;
  bool used = false;
  
  memcpy(cnt_cpy, cnt, sizeof cnt);
  bool found = false;
  for(int i = 1; i < 10; i++) {
    if(cnt_cpy[i] > 0) {
      recv[write++] = '0' + i;
      cnt_cpy[i]--;
      found = true;
      break;
    }
  }
  int dig = 0;
  if(!found) {
    memcpy(recv, sub, sizeof(char) * slen);
    write = slen;
    used = true;
  } else {
    if(recv[0] < sub[0] || sub[0] == '0') {
      memcpy(cnt, cnt_cpy, sizeof cnt);
    } else if(recv[0] > sub[0]) {
      memcpy(recv, sub, sizeof(char) * slen);
      write = slen;
      used = true;
    } else {
      bool done = false;
      for(int i = 1; i < slen; i++) {
	while(dig < 10 && cnt_cpy[dig] == 0)
	  dig++;
	if(dig == 10)
	  break;
	recv[write++] = '0' + dig;
	cnt_cpy[dig]--;
	if(sub[i] - '0' < dig) {
	  memcpy(recv, sub, sizeof(char) * slen);
	  write = slen;
	  used = true;
	  done = true;
	  break;
	} else if(sub[i] - '0' > dig) {
	  memcpy(cnt, cnt_cpy, sizeof cnt);
	  done = true;
	  break;
	}
      }
      if(!done) {
	memcpy(recv, sub, sizeof(char) * slen);
	write = slen;
	used = true;
	done = true;
      }
    }
  }
  dig = 0;
  while(dig < 10) {
    if(cnt[dig] && sub[0] == '0' + dig && !used) {
      //printf("if %d\n", dig);
      if(subadd < 0) {
	memcpy(recv + write, sub, sizeof(char) * slen);
	write += slen;
	used = true;
      } else {
	recv[write] = '0' + dig;
	write++;
	cnt[dig]--;
      }
    } else if(cnt[dig]) {
      //printf("else if %d\n", dig);
      recv[write] = '0' + dig;
      write++;
      cnt[dig]--;
    } else if(sub[0] == '0' + dig && !used) {
      //printf("else if2 %d\n", dig);
      memcpy(recv + write, sub, sizeof(char) * slen);
      used = true;
      write += slen;
    } else {
      //printf("else %d\n", dig);
      dig++;
    }
  }
  recv[write] = '\0';
  printf("%s\n", recv);
  return 0;
}
