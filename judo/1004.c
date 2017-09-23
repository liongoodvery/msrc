#include <stdio.h>

int main() {
    int aleng = 0;
    int bleng = 0;
    while (scanf("%d", &aleng) != EOF) {
        int a[aleng];
        for (int j = 0; j < aleng; ++j) {
            scanf("%d", &a[j]);
        }

        scanf("%d", &bleng);
        int b[bleng];
        for (int j = 0; j < bleng; ++j) {
            scanf("%d", &b[j]);
        }

        int imid = (aleng + bleng - 1) / 2;
        int ia = 0;
        int ib = 0;
        int ic = 0;
        int ret = a[0];
        while (ic <= imid) {

            if (ia >= aleng) {
                ret = b[ib];
                ib++;
                ic++;
                continue;
            }

            if (ib >= bleng) {
                ret = a[ia];
                ia++;
                ic++;
                continue;
            }

            if (a[ia] < b[ib]) {
                ret = a[ia];
                ia++;
                ic++;
            } else {
                ret = b[ib];
                ib++;
                ic++;
            }
        }

        printf("%d\n", ret);

    }
    return 0;
}