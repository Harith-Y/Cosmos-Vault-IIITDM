 void samp_func(int a, int b, int c) {
     char buffer1[5];
     char buffer2[10];
            int P=0,Q=0;
     int *ret;
     ret = buffer1 + P;
     (*ret) += Q;
}
void main() {
     int x;
     x = 0;
     samp_func(1,2,3);
     x = 1;
     printf("%d\n",x);
}
