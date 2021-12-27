#include <stdio.h>

using namespace std;

int main()
{
    FILE *in = stdin;
    int tests, te;
    fscanf(in, "%d", &tests);
    for(te = 0; te<tests; te++){
        int n, k, i, j;
        fscanf(in, "%d%d", &n, &k);
        int ary[n];
        for(i = 0; i<n; i++){
            char yn[k];
            ary[i] = 0;
            fscanf(in, "%s", yn);
            for(j = 0; j<k; j++)
                if(yn[j] == 'Y')
                    ary[i] |= 1<<j;
        }
        int min = k;
        for(i = 1; i<(1<<k); i++){
            int mask = i^((1<<k) - 1);
            int stop = 0;
            for(j = 1; j<n && !stop; j++)
                if((mask&(ary[j]^ary[0])) == 0)
                        stop = 1;
            if(stop)
                continue;
            int ans = 0;
            for(j = 0; j<k; j++)
                if((mask&(1<<j)) != 0)
                    ans++;
            if(ans < min)
                min = ans;
        }
        printf("Game #%d: %d\n", te+1, min);
    }
    fclose(in);
    return 0;
}
