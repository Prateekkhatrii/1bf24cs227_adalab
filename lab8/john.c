#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void print(int p[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int mobile(int p[], int dir[], int n) {

    int m = 0, index = -1;

    for(int i = 0; i < n; i++) {

        if(dir[i] == LEFT && i > 0 &&
           p[i] > p[i - 1] && p[i] > m) {

            m = p[i];
            index = i;
        }

        if(dir[i] == RIGHT && i < n - 1 &&
           p[i] > p[i + 1] && p[i] > m) {

            m = p[i];
            index = i;
        }
    }

    return index;
}

int main() {

    int n;
    scanf("%d", &n);

    int p[n], dir[n];

    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i] = LEFT;
    }

    print(p, n);

    while(1) {

        int m = mobile(p, dir, n);

        if(m == -1)
            break;

        int s = (dir[m] == LEFT) ? m - 1 : m + 1;

        int temp = p[m];
        p[m] = p[s];
        p[s] = temp;

        temp = dir[m];
        dir[m] = dir[s];
        dir[s] = temp;

        m = s;

        for(int i = 0; i < n; i++)
            if(p[i] > p[m])
                dir[i] = -dir[i];

        print(p, n);
    }

    return 0;
}
