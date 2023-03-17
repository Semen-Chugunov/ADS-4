// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        c+=1;
    }
  }
  return c;
}
int countPairs2(int *arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len -1; i < j; j--) {
      if (arr[i] + arr[j] == value)
        c+=1;
    }
  }
  return c;
}
int countPairs3(int *arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (1 < right - left) {
      int m = (left + right) / 2;
      if (arr[i] + arr[m] == value) {
          c++;
          int t = m + 1;
        while (arr[i] + arr[t] == value && t < right) {
          c++;
          t++;
        }
        t = m - 1;
        while (arr[i] + arr[t] == value && t > left) {
          c++;
          t--;
        }
        break;
      }
      if (arr[i] + arr[m] > value) {
        right = m;
      } else {
        left = m;
      }
    }
  }
  return c;
}
