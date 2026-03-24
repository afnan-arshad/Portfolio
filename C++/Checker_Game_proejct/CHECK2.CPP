#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<process.h>
/////////////////////////////////global varibal & functions/////////////////
int g1[8][8];
int g2[8][8],nm,baari=1;
int initWhite[8][8];
int checkWon(int g[8][8]);
//static int mv=0;
void initGraph();
void bckGrng();
////////////////////////////start of goti class////////////////////
class goti1{
private:
	int x;
	int y;
	int x1;
	int y1;
public:
	goti1();
       void c1Goti(int);
       void drawGoti1(int);
       char moveGoti1();
       void innerMove1(int,int);
       void Dselect1();
       void Cselect1(int,int);
       void draw1();
       void clear1();
};

goti1::goti1(){
	x=35;
	y=35;
	x1=0;
	y1=0;


}
void goti1::c1Goti(int c){
       drawGoti1(c);

}
void goti1::drawGoti1(int cl){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			 if((!g1[i][j] && initWhite[i][j]) && !g2[i][j]){
				setfillstyle(1,15);
				bar(10+j*50,10+i*50,60+j*50,60+i*50);//each bar of size 50 width.
			 }
			 else if(g1[i][j]==1){
				setfillstyle(1,cl);
				bar((x-10)+(j*50),(y-10)+(i*50),(x+10)+(j*50),(y+10)+(i*50));
			 }
			 else if(g1[i][j]==2){
				setfillstyle(1,cl);
				bar((x-10)+(j*50),(y-10)+(i*50),(x+10)+(j*50),(y+10)+(i*50));
				setfillstyle(1,0);
				bar((x-5)+(j*50),(y-5)+(i*50),(x+5)+(j*50),(y+5)+(i*50));
			 }
		}

	}
}
char goti1::moveGoti1(){

// mv=1-mv;
 char ch;
 nm=0;
 int temp1=0,temp2=0;
 baari=1;
 x1=y1=0;
		settextstyle(4,0,4);   //style,dir,size
		setfillstyle(1,4);
		bar(450,20,620,100);
		outtextxy(480,30,"Player 1");
		draw1();
		//clear0();
		ch=getch();
	       while(baari){
			ch=getch();
			switch(ch){
				case 75:{  //left
					if((x1>=100 && x1<=350)){
						clear1();
						x1-=100;
						draw1();
					}
					break;
				}
				case 77:{  //right
					if(x1>=0&&x1<300){
						clear1();
						x1+=100;
						draw1();
					}
				break;
				}
				case 72:{ //top
					if(y1>=50&&y1<=400){
						clear1();
						y1-=50;
					       if((!((y1/10)%2)))
							x1-=50;
						 else
							x1+=50;

						draw1();
					}
				break;
				}
				case 80:{  //bottom
					if(y1>=0&&y1<=300){
						clear1();
						y1+=50;
					       if(((y1/10)%2))
							x1+=50;
						else
							x1-=50;
						draw1();
					}
				break;
				}
				case 13:{
				    if(((g1[y1/50][x1/50]==1||g2[y1/50][x1/50]==1)||(g1[y1/50][x1/50]==2||g2[y1/50][x1/50]==2))||nm==1){
						Dselect1();
						if(++nm==2)
							innerMove1(temp1,temp2);
						else if(nm==1){
							temp1=x1;
							temp2=y1;
					      }
				      }
				      break;
				}
				case 27:{

					clear1();
					return ch;
				}
			}
		}
		clear1();
 return 0;
}

void goti1::innerMove1(int tp1,int tp2){
	Cselect1(tp1,tp2);
	Cselect1(x1,y1);							      //aik step move kry...
		if((!g1[y1/50][x1/50] && g1[tp2/50][tp1/50]==1 && !g2[y1/50][x1/50])&&((tp2/50+1==y1/50)&&(tp1/50+1==x1/50||tp1/50-1==x1/50))||
		  ((g1[tp2/50][tp1/50]==2 && (tp2/50+1==y1/50||tp2/50-1==y1/50)&&(tp1/50+1==x1/50||tp1/50-1==x1/50)))){
			if(g1[tp2/50][tp1/50]==2||y1==350||y1/50==7){
				g1[tp2/50][tp1/50]=0;
				g1[y1/50][x1/50]=2;
			}else{
				g1[tp2/50][tp1/50]=0;
				g1[y1/50][x1/50]=1;
			}

		drawGoti1(5);
		baari=0;
		}else if((g1[tp2/50][tp1/50]==1 && tp2/50+2==y1/50 && !g1[y1/50][x1/50] && !g2[y1/50][x1/50]&&(g2[(tp2/50)+1][(tp1/50)-1]==1&&tp1/50-2==x1/50||g2[(tp2/50)+1][(tp1/50)+1]==1&&tp1/50+2==x1/50))){
			       if((g2[(tp2/50)+1][(tp1/50)+1]==1 && tp1/50+2==x1/50))
					g2[(tp2/50)+1][(tp1/50)+1]=0;
			       else if((g2[(tp2/50)+1][(tp1/50)-1]==1 && tp1/50-2==x1/50))
					g2[(tp2/50)+1][(tp1/50)-1]=0;
			       g1[tp2/50][tp1/50]=0;
			       if(y1==350||y1/50==7)
					g1[y1/50][x1/50]=2;
			       else
					g1[y1/50][x1/50]=1;
			       drawGoti1(5);
			       drawGoti2(12);
			       baari=0;
		}else if(g1[tp2/50][tp1/50]==2 &&!g1[y1/50][x1/50] && !g2[y1/50][x1/50] &&((tp2/50+2==y1/50||tp2/50-2==y1/50)&&(tp1/50+2==x1/50||tp1/50-2==x1/50))
			 &&((g2[tp2/50-1][tp1/50-1]==1||g2[tp2/50-1][tp1/50-1]==2)
			 ||(g2[tp2/50-1][tp1/50+1]==1||g2[tp2/50-1][tp1/50+1]==2)
			 ||(g2[tp2/50+1][tp1/50-1]==1||g2[tp2/50+1][tp1/50-1]==2)
			 ||(g2[tp2/50+1][tp1/50+1]==1||g2[tp2/50+1][tp1/50+1]==2)
		)){
		   if((g2[tp2/50-1][tp1/50-1]==1||g2[tp2/50-1][tp1/50-1]==2)&&tp1/50-2==x1/50)
					       g2[(tp2/50)-1][(tp1/50)-1]=0;
				else if((g2[tp2/50-1][tp1/50+1]==1||g2[tp2/50-1][tp1/50+1]==2)&&tp1/50+2==x1/50)
					       g2[(tp2/50)-1][(tp1/50)+1]=0;
				else if((g2[tp2/50+1][tp1/50-1]==1||g2[tp2/50+1][tp1/50-1]==2)&&tp1/50-2==x1/50)
						g2[(tp2/50)+1][(tp1/50)-1]=0;
				else if((g2[tp2/50+1][tp1/50+1]==1||g2[tp2/50+1][tp1/50+1]==2)&&tp1/50+2==x1/50)
					       g2[(tp2/50)+1][(tp1/50)+1]=0;
				 g1[tp2/50][tp1/50]=0;
				 g1[y1/50][x1/50]=2;
			       drawGoti1(5);
			       drawGoti2(12);
			       baari=0;


		}else{
		      //sound(700);
		      //delay(200);
		       //nosound();

		settextstyle(4,0,3);
		outtextxy(460,300,"Invaild move");
		delay(1000);
		setfillstyle(1,4);
		bar(450,290,620,340);

		}

	nm=0;
}
void goti1::draw1(){
		setcolor(0);
		rectangle(20+x1,20+y1,50+x1,50+y1);
}
void goti1::Dselect1(){
     setcolor(0);
	 rectangle(15+x1,15+y1,55+x1,55+y1);
}
void goti1::Cselect1(int t1,int t2){
     setcolor(15);
	 rectangle(15+t1,15+t2,55+t1,55+t2);
}
void goti1::clear1(){
	setcolor(15);
	rectangle(20+x1,20+y1,50+x1,50+y1);
}
////////////////////////////////////////////2nd class/////////////////////////////////////
class goti2{
private:
	int x;
	int y;
	int x1;
	int y1;
public:
       goti2();
       void c2Goti(int);
       void drawGoti2(int);
       char moveGoti2();
       void innerMove2(int,int);
       void Dselect2();
       void Cselect2(int,int);
       void draw0();
       void clear0();
};
goti2::goti2(){
	x=35;
	y=35;
	x1=0;
	y1=0;


}
void goti2::c2Goti(int c){
	drawGoti2(c);
}

void goti2::drawGoti2(int cl){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			 if((!g2[i][j] && initWhite[i][j]) && !g1[i][j]){
				setfillstyle(1,15);
				bar(10+j*50,10+i*50,60+j*50,60+i*50);//each bar of size 50 width.
			 }
			 else if(g2[i][j]==1){
				setfillstyle(1,cl);
				bar((x-10)+(j*50),(y-10)+(i*50),(x+10)+(j*50),(y+10)+(i*50));
			 }
			 else if(g2[i][j]==2){
				setfillstyle(1,cl);
				bar((x-10)+(j*50),(y-10)+(i*50),(x+10)+(j*50),(y+10)+(i*50));
				setfillstyle(1,0);
				bar((x-5)+(j*50),(y-5)+(i*50),(x+5)+(j*50),(y+5)+(i*50));
			 }

		}

	}
}
char goti2::moveGoti2(){

// mv=1-mv;
 char ch;
 nm=0;
 int temp1=0,temp2=0;
 baari=1;
 x1=y1=0;
		setfillstyle(1,4);
		bar(450,20,620,100);
		settextstyle(4,0,4);
		outtextxy(480,30,"Player 2");
		draw0();
		//clear1();
		ch=getch();
		while(baari){
			ch=getch();
			switch(ch){
				case 75:{  //left
					if((x1>-300 && x1<=0)){
						clear0();
						x1-=100;
						draw0();
					}
					break;
				}
				case 77:{  //right
					if(x1>=-350 && x1<=-100){
						clear0();
						x1+=100;
						draw0();
					}
				break;
				}
				case 72:{ //top
					if(y1>=0&&y1<=300){
						clear0();
						y1+=50;
					    if((((y1/10)%2)))
							x1-=50;
					    else
							x1+=50;

						draw0();
					}
				break;
				}
				case 80:{  //bottom
					if(y1>=50&&y1<=400){
						clear0();
						y1-=50;
					       if((!((y1/10)%2)))
							x1+=50;
						else
							x1-=50;

						draw0();
					}
				break;
				}
				case 13:{
				      if(nm ==1 ||((g1[7-y1/50][7+x1/50]==1||g2[7-y1/50][7+x1/50]==1)||(g1[7-y1/50][7+x1/50]==2||g2[7-y1/50][7+x1/50]==2))){
					       Dselect2();
						if(++nm==2)
							innerMove2(temp1,temp2);
						else if(nm==1){
							temp1=x1;
							temp2=y1;
						}
				     }
				      break;
				}
				case 27:{

					clear0();
					return ch;
				}
			}
		}
		clear0();
 return 0;
}

void goti2::innerMove2(int tp1,int tp2){
	Cselect2(tp1,tp2);
	Cselect2(x1,y1);

		if((!g2[7-(y1/50)][7+(x1/50)] && g2[7-(tp2/50)][7+(tp1/50)]==1 && !g1[7-y1/50][7+x1/50])&&7-tp2/50-1==7-y1/50&&(7+tp1/50-1==7+x1/50||7+tp1/50+1==7+x1/50)||(g2[7-(tp2/50)][7+(tp1/50)]==2 && (7-tp2/50-1==7-y1/50||7-tp2/50+1==7-y1/50)&&(7+tp1/50-1==7+x1/50||7+tp1/50+1==7+x1/50))){
			if(g2[7-(tp2/50)][7+(tp1/50)]==2 || y1==350 || y1/50==7){
				g2[7-(tp2/50)][7+(tp1/50)]=0;
				g2[7-(y1/50)][7+(x1/50)]=2;

			}else{
				g2[7-(tp2/50)][7+(tp1/50)]=0;
				g2[7-(y1/50)][7+(x1/50)]=1;
			}
		drawGoti2(12);
		baari=0;
		}else if(g2[7-(tp2/50)][7+(tp1/50)]==1 && !g1[7-y1/50][7+x1/50]&&!g2[7-(y1/50)][7+(x1/50)]&& tp2/50+2==y1/50 &&(g1[(7-tp2/50)-1][(7+tp1/50)+1]==1 && tp1/50+2==x1/50 || g1[(7-tp2/50)-1][(7+tp1/50)-1]==1 &&tp1/50-2==x1/50)){
				if((g1[(7-tp2/50)-1][(7+tp1/50)+1]==1 && tp1/50+2==x1/50))
					g1[(7-tp2/50)-1][(7+tp1/50)+1]=0;
			       else if((g1[(7-tp2/50)-1][(7+tp1/50)-1]==1 && tp1/50-2==x1/50))
					g1[(7-tp2/50)-1][(7+tp1/50)-1]=0;
				g2[7-(tp2/50)][7+(tp1/50)]=0;
				if(y1==350||y1/50==7)
					g2[7-(y1/50)][7+(x1/50)]=2;
				else
					g2[7-(y1/50)][7+(x1/50)]=1;
				drawGoti(12,2);
				drawGoti(5,1);
				baari=0;
		}else if(g2[7-(tp2/50)][7+(tp1/50)]==2 && !g1[7-y1/50][7+x1/50]&& !g2[7-(y1/50)][7+(x1/50)] && (tp2/50+2==y1/50||tp2/50-2==y1/50)&&(tp1/50+2==x1/50||tp1/50-2==x1/50)&&
			((g1[(7-tp2/50)-1][(7+tp1/50)+1]==1||g1[(7-tp2/50)-1][(7+tp1/50)+1]==2)||
			(g1[(7-tp2/50)+1][(7+tp1/50)+1]==1||g1[(7-tp2/50)+1][(7+tp1/50)+1]==2)||
			(g1[(7-tp2/50)-1][(7+tp1/50)-1]==1||g1[(7-tp2/50)-1][(7+tp1/50)-1]==2)||
			(g1[(7-tp2/50)+1][(7+tp1/50)-1]==1||g1[(7-tp2/50)+1][(7+tp1/50)-1]==2))){
				if((g1[(7-tp2/50)-1][(7+tp1/50)+1]==1||g1[(7-tp2/50)-1][(7+tp1/50)+1]==2) &&tp1/50+2==x1/50)
						g1[(7-tp2/50)-1][(7+tp1/50)+1]=0;
				else if((g1[(7-tp2/50)+1][(7+tp1/50)+1]==1||g1[(7-tp2/50)+1][(7+tp1/50)+1]==2)&&tp1/50+2==x1/50)
						g1[(7-tp2/50)+1][(7+tp1/50)+1]=0;
				else if((g1[(7-tp2/50)-1][(7+tp1/50)-1]==1||g1[(7-tp2/50)-1][(7+tp1/50)-1]==2)&&tp1/50-2==x1/50)
						g1[(7-tp2/50)-1][(7+tp1/50)-1]=0;
				else if((g1[(7-tp2/50)+1][(7+tp1/50)-1]==1||g1[(7-tp2/50)+1][(7+tp1/50)-1]==2)&&tp1/50-2==x1/50)
						g1[(7-tp2/50)+1][(7+tp1/50)-1]=0;
				g2[7-(tp2/50)][7+(tp1/50)]=0;
				g2[7-(y1/50)][7+(x1/50)]=2;
				drawGoti(12,2);
				drawGoti(5,1);
				baari=0;

			}else{
		      //sound(700);
		      //delay(200);
		       //nosound();
		settextstyle(4,0,2);
		outtextxy(460,300,"Invaild move");
		delay(1000);
		setfillstyle(1,4);
		bar(450,290,620,340);

		}
	nm=0;
}

void goti2::Dselect2(){
     setcolor(0);
	 rectangle(365+x1,365-y1,405+x1,405-y1);
}
void goti2::Cselect2(int t1,int t2){
     setcolor(15);
	 rectangle(365+t1,365-t2,405+t1,405-t2);
}
void goti2::draw0(){
	setcolor(0);
	rectangle(370+x1,370-y1,400+x1,400-y1);
}

void goti2::clear0(){
       setcolor(15);
       rectangle(370+x1,370-y1,400+x1,400-y1);
}

int main(){
clrscr();
initGraph();
	bckGrng();
	goti1 gt1;
	goti2 gt2;
	gt1.c1Goti(5); //5 or 12
	gt2.c2Goti(12);
	char chck='\0';
	int r=0;
	while(chck!=27){
		if(chck!=27){
			chck=gt1.moveGoti1();
			if(checkWon(g1)){
			 r=1;
			break;
			}
		}
		if(chck!=27){
			chck=gt2.moveGoti2();
			if(checkWon(g2)){
			r=2;
			break;
			}
		}
	}
	if(r==1){
	cleardevice();
	settextstyle(4,0,5);
	outtextxy(200,getmaxy()/2,"player 1 win...");
	 getch();
	}
	if(r==2){
	cleardevice();
	settextstyle(4,0,5);
	outtextxy(200,getmaxy()/2,"player 2 win...");
	 getch();
	}
return 0;
}
///////////////////////////////////////////////////
void initGraph(){
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "c:\\tc\\bgi\\");
}
///////////////////////////Starting initailzation////////////////////////
void bckGrng(){
setbkcolor(0);
for(int i=0;i<3;i++)
	rectangle(0+i*5,0+i*5,getmaxx()-i*5,getmaxy()-i*5);
for(int k=0;k<8;k++){
		for(int m=0;m<8;m++){
			if(((k%2==0)&&(m%2==0))||((k%2==1)&&(m%2==1))) //for table
				initWhite[k][m]=1;
			else
				initWhite[k][m]=0;
			if(((k==6 && m%2==0)||(k==7 && m%2==1))) //2nd player goti
			      g2[k][m]=1;
			else
			 g2[k][m]=0;
			if(((k==0 && m%2==0)||(k==1 && m%2==1)))//1st player goti
				g1[k][m]=1;
			else
			 g1[k][m]=0;
		}
}
setfillstyle(1,4);
bar(415,15,getmaxx()-15,getmaxy()-15);
bar(15,415,getmaxx()-15,getmaxy()-15);
setfillstyle(1,15);
for(i=0;i<8;i++)
	for(int j=0;j<8;j++)
	    if(initWhite[i][j])
	       bar(10+j*50,10+i*50,60+j*50,60+i*50);//each bar of size 50 width.
}
int checkWon(int g[8][8]){
   for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
	 if(g[i][j]==1)
	    return 0;
	}
   }
return 1;
}
