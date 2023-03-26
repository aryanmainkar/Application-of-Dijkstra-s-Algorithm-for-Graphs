

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MaxGraphSize 50

typedef struct 
{
   char label[6];
   int distance;
   int previous;
   int visited;
}
Vertex;

void dijkstrasalgo(Vertex VertexArray[MaxGraphSize],int AdjMatrix[MaxGraphSize][MaxGraphSize],int VertexCount,char StartVertex[6])
{
   int CurrentVertex = 0;
   int dofu=0;
   int cofuv=0;
   int dofv=0;
   char EndVertex[6];
   int path[MaxGraphSize];
   int PathIndex = 0;
   int PrevIndex = -1;
   int DestIndex = 0;
   int Distance = 0;
    
   for(int i = 0;i<VertexCount;i++)
   {
       if(VertexArray[i].label==StartVertex)
       {
           CurrentVertex = i;
       }
   }
    
   VertexArray[CurrentVertex].distance = 0;
   VertexArray[CurrentVertex].previous = -1;
   VertexArray[CurrentVertex].visited = 1;
    
   for(int x = 0; x < VertexCount-1; x++)
   {
       for(int i = 0; i < VertexCount; i++)
       {
           if (AdjMatrix[CurrentVertex][i] != -1 && !VertexArray[i].visited) 
           {
               dofu = VertexArray[CurrentVertex].distance;
               cofuv = AdjMatrix[CurrentVertex][i];
               dofv = VertexArray[i].distance;

               if (dofu + cofuv < dofv)
               {
                   dofv = dofu + cofuv;
                   VertexArray[i].distance = dofv;
                   VertexArray[i].previous = CurrentVertex;
               }
           }
        }

       int SmallestVertexIndex = -1;
       int SmallestVertex = INT_MAX;

       for(int i = 0; i < VertexCount; i++)
       {
           if (!VertexArray[i].visited)
           {
               if (VertexArray[i].distance < SmallestVertex)
               {
                   SmallestVertex = VertexArray[i].distance;
                   SmallestVertexIndex = i;
               }
           }
       }
       CurrentVertex = SmallestVertexIndex;
       VertexArray[CurrentVertex].visited = 1;
       
    }

   #ifdef PRINTIT
       printf("\n\nI\tL\tD\tP\tV\n");
       for(int i = 0;i<VertexCount;i++)
       {
           printf("%d\t%s\t%d\t%d\t%d\n",i,VertexArray[i].label,VertexArray[i].distance,VertexArray[i].previous,VertexArray[i].visited);
       }
       printf("\n");
   #endif
    
   printf("What is the destination vertex?");
   scanf("%s",EndVertex);
   
   for(int i = 0;i<VertexCount;i++)
   {
       if(strcmp(VertexArray[i].label,EndVertex) == 0)
       {
           path[PathIndex] = i;
           DestIndex = i;
       }
   }
    
   Distance = VertexArray[DestIndex].distance;
   PrevIndex = VertexArray[DestIndex].previous;
    
   while(PrevIndex>=0 && PathIndex<VertexCount)
   {
       PathIndex++;   
       PrevIndex = VertexArray[DestIndex].previous;
       path[PathIndex] = PrevIndex;
       DestIndex = PrevIndex;
    }
    
   printf("The path from %s to %s is ",StartVertex,EndVertex);
    
   for(int i = PathIndex-1;i>0;i--)
   {
       printf("%s->",VertexArray[path[i]].label);
   }
   printf("%s and has a lenght of %d\n",VertexArray[path[0]].label,Distance);
   
}

void PrintMatrix(int AdjMatrix[MaxGraphSize][MaxGraphSize],int VertexCount)
{
   printf("\n");
   for(int i = 0;i<VertexCount;i++)
   {
       for(int j = 0;j<VertexCount;j++)
       {
           printf("%5d\t",AdjMatrix[i][j]);
       }
       printf("\n");
   }
}

int readfileintoarray(int argc, char *argv[], Vertex VertexArray[MaxGraphSize],int AdjMatrix[MaxGraphSize][MaxGraphSize])
{
   char buffer[MaxGraphSize];
   char *Token = NULL;
   int VertexCount = 0;
   int lenght=0;
   int index = 0;
   int edge=0;
    
   FILE *FH = NULL;
   FH = fopen(argv[1], "r");
   if(FH==NULL)
   {
       if(argc<2)
       {
           printf("Number of runs not specified on command line...defaulting to 10\n");
           printf("File must be provided on command line...exiting\n");
	       exit(0);    
       }
       printf("Invalid File Name...Exiting\n");
       exit(0);
   } 
    
   while (fgets(buffer, sizeof(buffer)-1, FH))
   {   
       lenght = strlen(buffer);
       
       if(buffer[strlen(buffer)-1] == '\n')
       {
           buffer[strlen(buffer)-1] = '\0';
       }
         
       Token = strtok(buffer,",");
        
       strcpy(VertexArray[VertexCount].label,Token);
       VertexArray[VertexCount].distance = INT_MAX;
       VertexArray[VertexCount].visited = 0;
       VertexArray[VertexCount].previous = 0;

       int counter=2;
       while(Token != NULL) 
       {
           if(counter>=lenght-1)
           {
               Token = NULL;
           }
           Token = strtok(NULL, ",");
        
           index = atoi(Token);
        
           Token = strtok(NULL,",");
           edge = atoi(Token);
           counter+=4;

           AdjMatrix[VertexCount][index] = edge;

           if(counter>=lenght-1)
           {
               Token = NULL;
           }
       }     
       VertexCount++;  
   } 
    
   #ifdef PRINTIT
       PrintMatrix(AdjMatrix,VertexCount);
   #endif
   fclose(FH);
   return VertexCount;

}

int main(int argc,char*argv[])
{
   Vertex VertexArray[MaxGraphSize]={{0}};
   char EndVertex[6];
   int AdjMatrix[MaxGraphSize][MaxGraphSize];
   char StartVertex[6];
   int VertexCount = 0;

   for(int i = 0;i<MaxGraphSize;i++)
   {
       for(int j = 0;j<MaxGraphSize;j++)
       {
           AdjMatrix[i][j] = -1;
       }
   }

   VertexCount = readfileintoarray(argc,argv,VertexArray,AdjMatrix);
   
   printf("What is the starting vertex?");
   scanf("%s",StartVertex);

   dijkstrasalgo(VertexArray,AdjMatrix,VertexCount,StartVertex);

   return 0;
}


