//TRABALHO DESENVOLVIDO PARA A DISCIPLINA
// DE COMPUTAÇÃO GRÁFICA
// DO CURSO DE ENGENHARIA DA COMPPUTAÇÃO
// DA UNIVERSIDADE FEDERAL DO VALE DO SÃO FRANCISCO
// NOME DOS INTEGRANTES: VICTOR AUGUSTO MEDEIROS BALBINO, PEDRO HENMRIQUE FERREIRA AMORIM DA SILVA


#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<math.h>
#include<string.h>
#include<time.h>

#include<Windows.h>
#include<MMSystem.h>

int x,y;
int i,count,pop;
char t[2];
char t1[2];
float px=90.0,py=15.0;
int flag, df=10;
clock_t start,end,now;

float r_obj=0.0,g_obj=0.0,b_obj=1.0;
float r_jan=0.0,g_jan=0.0,b_jan=0.0;
double r_lab=1.0,g_lab=1.0,b_lab=1.0;


int tocou=1;
int vidas= 3;
int press=1;

void point()
{

 //glColor3f(0.0,0.0,1.0);
 glColor3f(r_obj,g_obj,b_obj);

 glBegin(GL_POINTS);
 glVertex2f(px,py);
 glEnd();
}
void point1()
{

 glColor3f(.0,1.0,0.0);
 glBegin(GL_POINTS);
 glVertex2f(90.0,15.0);
 glEnd();
}
void point2()
{

 glColor3f(1.0,0.0,.0);
 glBegin(GL_POLYGON);
 glVertex2f(20,160.0);
 glVertex2f(40,160.0);
 glVertex2f(40,175.0);
 glVertex2f(20,175.0);

 glEnd();
}

void output(int x, int y, char *string)
{
      int len, i;

           glRasterPos2f(x,y);
           len=(int) strlen(string);
           for (i = 0; i < len; i++)
			{
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
			}
}

void drawstring(int x, int y, char *string,void *font)
{
      int len, i;

           glRasterPos2f(x,y);
           len=(int) strlen(string);
           for (i = 0; i < len; i++)
			{
             glutBitmapCharacter(font,string[i]);
			}
}


 void winscreen()
 {
	glClear(GL_COLOR_BUFFER_BIT);
	sndPlaySound("victory.wav", SND_FILENAME | SND_ALIAS);
	glLoadIdentity();
	glColor3f(0.0,1.0,0.0);
	output(55,120,"PARABENS!!!");
	glColor3f(1.0,0.0,1.0);
	output(15,100,"VOCE COMPLETOU O GRANDE DESAFIO DO LABIRINTO");
	 output(35,60,"* PRESSIONE ESC PARA RETORNAR AO MENU INICIAL");
     output(35,45,"* PRESSIONE 1 PARA REINICIAR O JOGO");
     
	glFlush();
 }
void startscreen()
{

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);
output(25,140,"BEM VINDO AO JOGO DO LABIRINTO MISTERIOSO");
output(50,100,"1.NOVO JOGO");
output(50,80,"2.INSTRUCOES");
output(50,60,"3.SAIR");
glFlush();
}

void instructions()
{
  glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);
    output(45,140,"INSTRUCOES:");
	glBegin(GL_LINES);
	glVertex2f(45,138);
	glVertex2f(90,138);
	glEnd();
	glColor3f(0,1,0);
  output(-20,120,"* PARA MOVER O OBJETO USE AS TECLAS DIRECIONAIS");
  output(-20,100,"* MOVA O OBJETO ATE O RETANGULO INDICADO PARA VENCER O JOGO");
  output(-20,80,"* CASO VOCE TOQUE NA PAREDE, PERDERA UMA VIDA");
  //output(-20,60,"* RED COLOURED POINT INDICATE THE POINT WHERE YOU HAVE TO REACH");
  output(-20,40,"* VOCE TEM 3 VIDAS E DEVE COMPLETAR O JOGO ANTES DO TEMPO ACABAR");
  output(-20,20,"* PRESSIONE ESC PARA RETORNAR AO MENU PRINCIPAL");
   glFlush();
}

void timeover()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1.0);
 sndPlaySound("uepa.wav", SND_FILENAME | SND_ALIAS);
 output(70,110,"GAME OVER");
 glColor3f(0,1,0);
 output(50,100,"VOCE PERDEU O JOGO");
 output(50,90,"MAIS SORTE NA PROXIMA VEZ, OU AGILIDADE");
 //output(40,40,"* PRESS ESC TO GO TO MAIN MENU");
 output(40,30,"* PRESSIONE 1 PARA REINICIAR O JOGO");
 vidas=3;

 glFlush();
}
void delay(int milliseconds)
{
    long pause;
    clock_t then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
void demo_menu(int id)
{
	switch(id)
	{
	case 1:
		   df=2;
		   instructions();

		    break;
	case 2:
		    exit(0);
	case 3:
		   
	  
     delay(10000);
     start=now;
	 df=1;
	 //glutPostRedisplay();
	 break;

			
	}
	//glutPostRedisplay();
}



void idle()
{
  if(df==1)
  {
    end=clock();
    count=(end-start)/CLOCKS_PER_SEC;


    if(count==300 || vidas==0)
    {
       df=4;
    }
	else
	if((count<300) && ((px>=20 && px<=40) && (py>=160 && py<=175)))
	{
		df=5;
	}
  }

   glutPostRedisplay();
}

void wall(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,GLfloat x3,GLfloat y3,GLfloat x4,GLfloat y4)
{
	glColor3f(r_lab,g_lab,b_lab);
  glBegin(GL_POLYGON);
	glVertex3f(x1,y1,0);
	glVertex3f(x2,y2,0);
	glVertex3f(x3,y3,0);
	glVertex3f(x4,y4,0);
  glEnd();

}

 void paredes(){
 	
 	//glColor3f(1.0,1.0,1.0);
		
		wall(-4,-4,0,-4,0,162,-4,162);
	    wall(-4,178,-4,184,184,184,184,178);
		wall(180,178,184,178,184,-4,180,-4);
		wall(180,0,180,-4,-4,-4,0,0);
		
		//sentido anti horario
		//level 1
		wall(0,30,42,30,      42,35,0,35);
		wall(70,30,180,30,      180,35,70,35);
		
		//level 2
		wall(0,50,130,50,      130,55,0,55);
		wall(150,50,180,50,      180,55,150,55);	

		//level 3
		wall(0,70,80,70,      80,75,0,75); 
		wall(90,70,180,70,      180,75,90,75);
		
		//level 4
		wall(15,90,160,90,      160,95,15,95); 

		//level 5
		wall(0,110,40,110,      40,115,0,115); 
		wall(60,110,110,110,      110,115,60,115);
		
		wall(125,110,180,110,      180,115,125,115); 
		
			
		//level 6
		wall(0,130,20,130,      20,135,0,135); 
		wall(35,130,140,130,      140,135,35,135);
		
		wall(150,130,180,130,      180,135,150,135);
		
		//level 7
		wall(0,150,100,150,      100,155,0,155); 
		wall(120,150,180,150,      180,155,120,155); 
		
		//wall(0,150,100,150,      20,155,0,155); 
			
		glutPostRedisplay();
 	
 	
 }

void GerenciaMouse(int button, int state, int x, int y)
{
	float semente1,semente2,semente3,semente4,semente5,semente6,semente7,semente8,semente9;
	srand((unsigned)time(NULL));
    if (button == GLUT_LEFT_BUTTON){
        	
        	 semente1 = rand() % 100; semente2 = rand() % 100; semente3 = rand() % 100;
        	 semente4 = rand() % 100; semente5 = rand() % 100; semente6 = rand() % 100;
        	 semente7 = rand() % 100; semente8 = rand() % 100; semente9 = rand() % 100;

         	 r_obj=semente1 / 100; g_obj=semente2 / 100; b_obj=semente3 / 100;
	 		 r_jan=semente4 / 100; g_jan=semente5 / 100; b_jan=semente6 / 100;
	 		 r_lab= semente7 / 100; g_lab=semente8 / 100; b_lab=semente9 / 100;
	 		printf("r: %f | g: %f | b: %f", r_lab , g_lab, g_lab);

			  paredes();
			  point();
			  glClearColor(r_jan, g_jan, b_jan,0.0);

	 		 glutPostRedisplay();
	 		 //printf("aperto: %d ", press);
         	 
         	 /*
     	if(press==2){
     		 r_obj=0.0; g_obj=0.0; b_obj=1.0;
	 		 r_jan=0.0; g_jan=0.0; b_jan=0.0;
	 		 r_lab=1.0; g_lab=1.0; b_lab=1.0;
	 		 glutPostRedisplay();
 	 		 printf("aperto: %d ", press);

			press++;
		}
		if(press==3){
			 r_obj=0.0; g_obj=0.0; b_obj=1.0;
	 		 r_jan=0.0; g_jan=0.0; b_jan=0.0;
	 		 r_lab=1.0; g_lab=1.0; b_lab=1.0;
			  glutPostRedisplay();	
  	 		 printf("aperto: %d ", press);
		
			press=1;
		 }
		 */
	}
    glutPostRedisplay();
}




void SpecialKey(int key, int x, int y)
{
  switch (key)
  {
	case GLUT_KEY_UP:
		flag=0;
		
	    if(py<175)
		if(!((px>=68 && px<=180) && (py>=25 && py<=35)))
		if(!((px>=0 && px<=42) && (py>=25 && py<=35)))

		//lvl 2
		if(!((px>=0 && px<=132) && (py>=45 && py<=55)))
		if(!((px>=150 && px<=180) && (py>=45 && py<=55)))

		//lvl 3
		if(!((px>=0 && px<=82) && (py>=65 && py<=75)))
		if(!((px>=88 && px<=180) && (py>=65 && py<=75)))

		//lvl 4
		if(!((px>=13 && px<=162) && (py>=85 && py<=95)))

		//lvl 5
		if(!((px>=0 && px<=42) && (py>=105 && py<=115)))
		if(!((px>=58 && px<=112) && (py>=105 && py<=115)))
		if(!((px>=123 && px<=180) && (py>=105 && py<=115)))

		//lvl 6
		if(!((px>=0 && px<=22) && (py>=125 && py<=135)))
		if(!((px>=33 && px<=142) && (py>=125 && py<=135)))
		if(!((px>=148 && px<=180) && (py>=125 && py<=135)))

		//lvl 7
		if(!((px>=0 && px<=102) && (py>=145 && py<=155)))
		if(!((px>=118 && px<=180) && (py>=145 && py<=155))){

		py=py+4;
		tocou=0;  }
		if (tocou == 1){ 
			px=90.0;
   			py=15.0;
   			printf("tocou:");
			   vidas= vidas-1;
			    sndPlaySound(TEXT("rapaz.wav"), SND_ASYNC );

   		}
   		printf("tocou: %d", tocou);
   		//tenho que botar esse comando pra ele sempre ficar 1 e so alterar caso nao toque
   		tocou=1;
		glutPostRedisplay();
		break;


	case GLUT_KEY_DOWN:

	flag=0;
	//aumento 5 nas coordenadas y
	    if(py>5)
		if(!((px>=68 && px<=180) && (py>=35 && py<=40)))
		if(!((px>=0 && px<=42) && (py>=3 && py<=35)))

		//lvl 2
		if(!((px>=0 && px<=132) && (py>=55 && py<=60)))
		if(!((px>=150 && px<=180) && (py>=55 && py<=60)))

		//lvl 3
		if(!((px>=0 && px<=82) && (py>=75 && py<=80)))
		if(!((px>=88 && px<=180) && (py>=75 && py<=80)))

		//lvl 4
		if(!((px>=13 && px<=162) && (py>=95 && py<=100)))

		//lvl 5
		if(!((px>=0 && px<=42) && (py>=115 && py<=120)))
		if(!((px>=58 && px<=112) && (py>=115 && py<=120)))
		if(!((px>=123 && px<=180) && (py>=115 && py<=120)))

		//lvl 6
		if(!((px>=0 && px<=22) && (py>=130 && py<=135)))
		if(!((px>=33 && px<=142) && (py>=130 && py<=135)))
		if(!((px>=148 && px<=180) && (py>=130 && py<=135)))

		//lvl 7
		if(!((px>=0 && px<=102) && (py>=155 && py<=160)))
		if(!((px>=118 && px<=180) && (py>=155 && py<=160))){	
		py=py-4;
		tocou=0;  }
		if (tocou == 1){ 
			px=90.0;
   			py=15.0;
   			printf("tocou:");
   			sndPlaySound(TEXT("rapaz.wav"), SND_ASYNC );
		    vidas= vidas-1;

   		}
   		printf("tocou: %d", tocou);
   		//tenho que botar esse comando pra ele sempre ficar 1 e so alterar caso nao toque
   		tocou=1;
		glutPostRedisplay();
		break;


	case GLUT_KEY_LEFT:
		flag=0;
	    if(px>0)
		if(!((px>=66 && px<=180) && (py>=30 && py<=35)))
		if(!((px>=0 && px<=46) && (py>=30 && py<=35)))

		//lvl 2
		if(!((px>=0 && px<=136) && (py>=50 && py<=55)))
		if(!((px>=148 && px<=180) && (py>=50 && py<=55)))

		//lvl 3
		if(!((px>=0 && px<=84) && (py>=70 && py<=75)))
		if(!((px>=88 && px<=180) && (py>=70 && py<=75)))

		//lvl 4
		if(!((px>=13 && px<=165) && (py>=90 && py<=95)))

		//lvl 5
		if(!((px>=0 && px<=46) && (py>=110 && py<=115)))
		if(!((px>=58 && px<=114) && (py>=110 && py<=115)))
		if(!((px>=123 && px<=180) && (py>=110 && py<=115)))

		//lvl 6
		if(!((px>=0 && px<=24) && (py>=125 && py<=135)))
		if(!((px>=33 && px<=144) && (py>=125 && py<=135)))
		if(!((px>=148 && px<=180) && (py>=125 && py<=135)))

		//lvl 7
		if(!((px>=0 && px<=106) && (py>=150 && py<=155)))
		if(!((px>=118 && px<=180) && (py>=150 && py<=155))){	
		px=px-3;
		tocou=0;  }
		if (tocou == 1){ 
			px=90.0;
   			py=15.0;
   			printf("tocou:");
   			sndPlaySound(TEXT("danca.wav"), SND_ASYNC );

			vidas= vidas-1;

   		}
   		printf("tocou: %d", tocou);
   		//tenho que botar esse comando pra ele sempre ficar 1 e so alterar caso nao toque
   		tocou=1;
		glutPostRedisplay();
		break;


	case GLUT_KEY_RIGHT:
		flag=0;
	    if(px<175)
		if(!((px>=66 && px<=180) && (py>=30 && py<=35)))
		if(!((px>=0 && px<=46) && (py>=30 && py<=35)))

		//lvl 2
		if(!((px>=0 && px<=134) && (py>=50 && py<=55)))
		if(!((px>=146 && px<=180) && (py>=50 && py<=55)))

		//lvl 3
		if(!((px>=0 && px<=84) && (py>=70 && py<=75)))
		if(!((px>=82 && px<=180) && (py>=70 && py<=75)))

		//lvl 4
		if(!((px>=12 && px<=164) && (py>=90 && py<=95)))

		//lvl 5
		if(!((px>=0 && px<=44) && (py>=110 && py<=115)))
		if(!((px>=56 && px<=114) && (py>=110 && py<=115)))
		if(!((px>=121 && px<=180) && (py>=110 && py<=115)))

		//lvl 6
		if(!((px>=0 && px<=24) && (py>=125 && py<=135)))
		if(!((px>=30 && px<=144) && (py>=125 && py<=135)))
		if(!((px>=154 && px<=180) && (py>=130 && py<=135)))

		//lvl 7
		if(!((px>=0 && px<=104) && (py>=150 && py<=155)))
		if(!((px>=116 && px<=180) && (py>=150 && py<=155)))	{
		px=px+3;tocou=0;  }
		if (tocou == 1){ 
			px=90.0;
   			py=15.0;
   			printf("tocou:");
   			sndPlaySound(TEXT("danca.wav"), SND_ASYNC );
			vidas= vidas-1;

   		}
   		printf("tocou: %d", tocou);
   		tocou=1;
			
		glutPostRedisplay();
		break;
		
  }
}

void display()
{

   glClear(GL_COLOR_BUFFER_BIT);


  if(df==0)
      startscreen();
    else if(df==1)
     {
		output(10,10,"INICIO");
		output(0,170,"FINAL");
		glColor3f(0.0,0.0,1.0);
		output(185,160,"TEMPO RESTANTE : ");
		//drawstring(190,130,"HURRY UP",GLUT_BITMAP_HELVETICA_18);
		glColor3f(1,0,0);
	    drawstring(190,140,"VIDAS RESTANTES: ",GLUT_BITMAP_HELVETICA_18);
		sprintf(t,"%d",300-count);
        output(240,160,t);

		sprintf(t1,"%d",vidas);
        output(240,140,t1);
        
        paredes();

        glutPostRedisplay();
		point();
		point1();
		point2();
		//line();
        

	}

 else if(df==2)
        instructions();
    else if(df==3)
     {
      exit(1);
     }
	else if(df==4)
	{
		timeover();
	}
	else if(df==5)
	{
		winscreen();
	}
	/*
	else if(tocou==1){
		px=90.0;
   		py=15.0;
	}
	*/

  glFlush();

}
void keyboard(unsigned char key,int x,int y)
{

if(df==10 )
df=0;


    else if((df==0 || df==4 || df==5)&& key=='1')
   {
     df=1;
     start=clock();
	 glutPostRedisplay();
   }
  else if(df==0 && key=='2')
   df=2;
  else if(df==0 && key=='3')
   df=3;
  else if(key==27)
   {	df=0;
	}
	if((key=='0' || key=='1')&& (df==4||df==1))
  {
   px=90.0;
   py=15.0;
  }
  glutPostRedisplay ();
}
void myinit()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //definindo o tamanho do quadrado
  glPointSize(25.0);

  glMatrixMode(GL_MODELVIEW);
  glClearColor(r_jan, g_jan, b_jan,0.0);

}

void myreshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		gluOrtho2D(45.0,135.0,-2.0*(GLfloat)h/(GLfloat)w,180.0*(GLfloat)h/(GLfloat)w);
	else
		gluOrtho2D(-45.0*(GLfloat)w/(GLfloat)h,135.0*(GLfloat)w/(GLfloat)h,-2.0,180.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
 }
 

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1350,700);
  glutCreateWindow("LABIRINTO GAME");
  glutDisplayFunc(display);
  glutReshapeFunc(myreshape);
  glutIdleFunc(idle);
  glutMouseFunc(GerenciaMouse);

  glutSpecialFunc(SpecialKey);
  glutKeyboardFunc(keyboard);

  
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  
  myinit();
  glutMainLoop();
  return 0;
}





