#include<stdio.h>
#include<stdlib.h>
#define maxv 1005
#define maxe 100005

int matrix[maxv][maxv]; //adjacency matrix
int input[maxv][maxv]; //used to store the input sequence

int ifDijkstra(int numv,int index){
    // create a hash_set S to check whether the vertices have been visited
    int s[numv+1];
    // init the hash_set
    for(int i = 1;i <= numv;i++) s[i] = 0;
    // get the source
    int source = input[index][0];
    s[source] = 1;
    // init the dist 
    int dist[numv+1];
    for(int i = 1;i<=numv;i++){
        if(i == source) dist[i] = 0; //if it is the source
        //this means there is no path betwenn source and i
        else if(matrix[source][i] == 0) dist[i] = INT_MAX; 
        else dist[i] = matrix[source][i];
    }
    // get the sequence
    int cnt = 1;
    // if the number of vertices is less than 2
    while(cnt < numv){
        // find the min dist
        int mindist = 0;
        for(int i = 1;i<=numv;i++){
            if(s[i] == 1) continue; //if it has been visited
            // if it is the first non-visited vertex
            if(dist[i] != 0 && mindist == 0) mindist = dist[i];
            // if the new dist is smaller than the current min dist
            if(dist[i] > 0 && dist[i] < mindist) mindist = dist[i];
        }
        //check whether the input is min dist
        int newv = input[index][cnt];
        if(dist[newv] != mindist) return 0;
        else s[newv] = 1; //mark it as visited
        cnt++;
        for(int i = 1;i<=numv;i++) //update the dist
                // if there is a new path between source and i and the new path is shorter
                if(s[i]==0&&matrix[newv][i] != 0 && dist[newv] + matrix[newv][i] < dist[i])
                    dist[i] = dist[newv] + matrix[newv][i];
    }
    return 1;
}

int main(int argc,char *argv[]){
    // The basic operation according to the question
    char in[30] = ".\\data\\data1.in";
    char out[30] = ".\\data\\data1.out";
    // chaning dirs according to the system
    if(argv[1][1] == 'l') in[1]=in[6]=out[1]=out[6]='/';
    in[11] = out[11] = argv[2][1];
    // represent the input file and output file
    printf("in:%s\n",in);
    printf("out:%s\n",out);
    FILE *fp = fopen(in,"r"); //open the input file
    FILE *fpp = fopen(out,"w+"); //open the output file
    // get the number of vertices and edges
    int numv,nume;
    fscanf(fp,"%d %d",&numv,&nume);
    //if there is no vertices or edges
    if(numv == 0 || nume == 0) return 0; 
    // init the matrix
    for(int i = 0;i<nume;i++){
        int v1,v2,w;
        fscanf(fp,"%d %d %d",&v1,&v2,&w);
        // store the weight of the edge between v1 and v2
        matrix[v1][v2] = matrix[v2][v1] = w; 
    }
    int k; // get the input sequence
    fscanf(fp,"%d",&k);
    for(int i = 0;i<k;i++){
        for(int j = 0;j<numv;j++) fscanf(fp,"%d",&input[i][j]);
    }
    // check whether the input sequence is the Dijkstra sequence
    for(int i = 0;i<k;i++){
        if(ifDijkstra(numv,i)) fprintf(fpp,"Yes\n");
        else fprintf(fpp,"No\n"); //if it is not the Dijkstra sequence
    }
}