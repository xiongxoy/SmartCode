/*============================================
 * DAG 的深度优先搜索标记
 * INIT: edge[][] adjacency matrix; 
   pre[] post[], tag all set to zero
 * CALL: dfstag(i, n); pre/post: start/end time
 *=============================================*/

int edge[V][V], pre[V], post[V], tag;
void dfstag(int cur, int n)
{  // vector: 0 ~ n-1
    pre[cur] = ++tag;
    for (int i=0; i < n; ++i) 
        if (edge[cur][i]) {
            if (0 == pre[i]) {
                printf("Tree Edge!\n");
                dfstag(i,n);
            }
            else {
                if ( 0 == post[i] ) 
                    printf("Back Edge!\n");
                else if (pre[i] > pre[cur])
                    printf("Down Edge!\n");
                else 
                    printf("Cross Edge!\n");
            }
        }
    post[cur] = ++tag;
}
