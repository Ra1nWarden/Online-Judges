#include <cstdio>
#include <cstring>

using namespace std;

const char orig[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
const char derived_start[] = "What are you doing while sending \"";
const char derived_mid[] = "\"? Are you busy? Will you send \"";
const char derived_end[] = "\"?";
const int maxn = 1e5;
const  int start_len = strlen(derived_start);
const  int mid_len = strlen(derived_mid);
const  int end_len = strlen(derived_end);
long long lengths[maxn+5];
int cap;

void init() {
  lengths[0] = strlen(orig);
  for(int i = 1; i <= maxn; i++) {
    lengths[i] = (long long) start_len + lengths[i-1] + mid_len + lengths[i-1] + end_len;
    if(lengths[i] > 1e18) {
      cap = i;
      break;
    }
  }
}

char query(int n, long long k) {
  if(n > cap) {
    if(k > start_len)
      return query(n-1, k-start_len);
    else
      return derived_start[k-1];
  }
  if(lengths[n] < k) {
    return '.';
  }
  if(n == 0)
    return orig[k-1];
  if(k <= start_len) {
    return derived_start[k-1];
  }
  else if(k <= start_len + lengths[n-1]) {
    return query(n-1, k-start_len);
  }
  else if(k <= start_len + lengths[n-1] + mid_len) {
    return derived_mid[k-start_len-lengths[n-1]-1];
  }
  else if(k <= start_len + lengths[n-1] + mid_len + lengths[n-1]) {
    return query(n-1, k-start_len-lengths[n-1]-mid_len);
  }
  else {
    return derived_end[k-start_len-lengths[n-1]-mid_len-lengths[n-1]-1];
  }
}

int main() {
  init();
  int q;
  scanf("%d", &q);
  while(q--) {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    printf("%c", query(n, k));
  }
  printf("\n");
  return 0;
}
