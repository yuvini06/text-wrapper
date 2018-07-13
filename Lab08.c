#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char **argv){

   FILE * pFile;
   char word[50];
   char max_size,c;
   char *input=argv[1];
   char *input_file=argv[2];
   int size,max_width,word_length,length; 
   
   word_length=0;
   length=0;  
   max_width= atoi(input);

   
   if(argc!=3){			
      printf("Usage: %s <width> <input-file> \n",argv[0]);
      return 0;
   }
   
   // If a negative integer is given as an input
   if(max_width<0){     
         pFile = fopen(input_file,"r");
         
         while(fscanf(pFile,"%s%c",word,&c) != EOF){ 
            if(c=='\n'){ 
                  printf("\n%s\n",word);      
            }

            else{
                  printf("\n%s",word);
            }
         }
         fclose(pFile);
         return 0;

   }

	pFile = fopen(input_file, "r");	// Checking the maximum word length 			
   	while(!feof(pFile)){
    	fscanf(pFile,"%s",word);
      	size=strlen(word);
      	if(length<size){
        	length=size;
      	}      
   	}	
   	max_size=length;
   	fclose(pFile);

   	if(max_width < max_size){
      	printf("Word length must be less than screen width\n");
      	return 0;
   	}

  

	pFile = fopen(input_file,"r");
   		
   		while(fscanf(pFile,"%s%c",word,&c) != EOF){ 

   			if(c=='\n'){
   				word_length=word_length+strlen(word);
               if (word_length<=max_width){
                  printf("%s\n",word);
                  word_length=0;
               }
               else{
                  printf("\n%s\n",word);
                  word_length=0;
               }
   			}


            else{
               word_length=word_length+strlen(word);
               if (word_length<=max_width){
                  printf("%s ",word);
                  word_length=word_length+1;
               }
               else{
                  printf("\n%s ",word);
                  word_length=strlen(word)+1;
               }
            }
	
   		}

   fclose(pFile);	
   return 0;
}
