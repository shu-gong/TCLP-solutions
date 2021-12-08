#include <stdio.h>

#define TAB 4       // This is the size of the tab columns.

#define MAXSITE 40  // Max number of characters in a line,
		    // must be larger than the longest word.
main()
{
  int site = 0, last = 0, c, i, col = 0;
  char line[MAXSITE];
	
  while((c = getchar()) != EOF){
		
    line[site] = c;    // We store each line in a temporary array
						
    if(c == '\t' && col <= MAXSITE - TAB){  // This controls the
					    // correct spacing
      for(i = col%TAB; i < TAB ; ++i){      // of the text with 
        line[site] = ' ';                   // the tabs sizes.
        ++site;
      }
				
      col += (TAB - col%TAB);
    }
		
    if(c != '\t'){
      ++site;
      ++col;
    }
				
    if(c == ' ' || c == '\t')
      last = site - 1;    // This is a marker of the last
			  // white space in a line.
								
    if(c == '\n'){          // Lines shorter than the max
      line[site] = '\0';    // lenght are written 'as is'.
      printf("%s", line);
      site = last = 0;
      col = 0;
    }
			 
    if(site == MAXSITE){    // Lines longer than the max lenght
			    // are written until the last space.
      for(i = 0; i < last; ++i)
        printf("%c", line[i]);
			
      putchar('\n');
			
      for(i = 0; i < MAXSITE - last; ++i)
        if(line[last + i + 1] != ' ' || line[last + i + 1] != '\t')
          line[i] = line[last + i + 1];
			
      site = MAXSITE - last - 1;
			
      col = site;
    }
  }
	
  for(i = 0; i < site; ++i)    // This writes the last input line.
    printf("%c", line[i]);
		
  putchar('\n');
}
