#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cv.h>			//Open CV涵式庫 
#include <highgui.h>	//Open CV涵式庫

IplImage *A1,*A2,*A3,*A4,*B1,*B2,*B3,*B4,*C1,*C2,*C3,*C4,*Blank,*cursor,*map,*mask,*mask1,*mask2;

int chessman[4][3]={ 13,11,12,
					  0,14, 0,
					  0, 4, 0,
					  2, 1, 3 }; //棋盤 
int eat[3][2]={0,0,
			   0,0,
			   0,0}; //吃掉的棋子 
					  
int cursit = 11; //Cursor位置 

int curindex()
{
	switch(cursit)
	{
		case 1:
			return 14;
		case 2:
			return 13;
		case 3:
			return 12;
		case 16:
			return 2;
		case 17:
			return 3;
		case 18:
			return 4;
		default:
			{
				return chessman[(cursit-4)%4][(cursit-4)/4];
			}
	}
}

int chessX(int index){return (index-4)/4;}
int chessY(int index){return (index-4)%4;}

int temp[2] = {0,0};

int main()
{
	int x,y;
	int A1x=260,A1y=50,A2x=260,A2y=233,A3x=260,A3y=420,A4x=260,A4y=605; //棋盤坐標 
	int B1x=441,B1y=50,B2x=441,B2y=233,B3x=441,B3y=420,B4x=441,B4y=605;
	int C1x=627,C1y=50,C2x=627,C2y=233,C3x=627,C3y=420,C4x=627,C4y=605;
	int L1x= 30,L1y=50,L2x= 30,L2y=233,L3x= 30,L3y=420;
	int                R2x=840,R2y=233,R3x=840,R3y=420,R4x=840,R4y=605;
	
	
	char directKey; 
	
	do
	{
		
	    map=cvLoadImage("map.png");  //載入背景圖片
	    
	    switch(chessman[0][0])
	    {
	    	case 0:
	    		{	A1 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	A1 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	A1 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	A1 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	A1 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	A1 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	A1 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	A1 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	A1 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	A1 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	A1 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[1][0])
	    {
	    	case 0:
	    		{	A2 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	A2 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	A2 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	A2 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	A2 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	A2 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	A2 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	A2 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	A2 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	A2 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	A2 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[2][0])
	    {
	    	case 0:
	    		{	A3 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	A3 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	A3 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	A3 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	A3 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	A3 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	A3 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	A3 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	A3 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	A3 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	A3 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[3][0])
	    {
	    	case 0:
	    		{	A4 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	A4 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	A4 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	A4 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	A4 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	A4 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	A4 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	A4 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	A4 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	A4 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	A4 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[0][1])
	    {
	    	case 0:
	    		{	B1 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	B1 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	B1 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	B1 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	B1 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	B1 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	B1 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	B1 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	B1 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	B1 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	B1 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[1][1])
	    {
	    	case 0:
	    		{	B2 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	B2 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	B2 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	B2 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	B2 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	B2 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	B2 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	B2 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	B2 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	B2 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	B2 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[2][1])
	    {
	    	case 0:
	    		{	B3 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	B3 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	B3 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	B3 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	B3 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	B3 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	B3 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	B3 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	B3 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	B3 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	B3 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[3][1])
	    {
	    	case 0:
	    		{	B4 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	B4 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	B4 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	B4 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	B4 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	B4 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	B4 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	B4 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	B4 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	B4 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	B4 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[0][2])
	    {
	    	case 0:
	    		{	C1 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	C1 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	C1 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	C1 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	C1 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	C1 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	C1 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	C1 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	C1 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	C1 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	C1 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[1][2])
	    {
	    	case 0:
	    		{	C2 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	C2 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	C2 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	C2 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	C2 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	C2 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	C2 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	C2 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	C2 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	C2 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	C2 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[2][2])
	    {
	    	case 0:
	    		{	C3 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	C3 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	C3 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	C3 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	C3 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	C3 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	C3 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	C3 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	C3 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	C3 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	C3 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    
	    switch(chessman[3][2])
	    {
	    	case 0:
	    		{	C4 = cvLoadImage("0.png");	//載入　　圖片
	    			break;
	    		}
	    	case 1:
	    		{	C4 = cvLoadImage("1.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 2:
	    		{	C4 = cvLoadImage("2.png");	//載入　　圖片
	    			break;
	    		}
	    	case 3:
	    		{	C4 = cvLoadImage("3.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 4:
	    		{	C4 = cvLoadImage("4.png");	//載入　　圖片
	    			break;
	    		}
	    	case 5:
	    		{	C4 = cvLoadImage("5.png");	//載入我方獅子圖片
	    			break;
	    		}
			case 11:
	    		{	C4 = cvLoadImage("11.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 12:
	    		{	C4 = cvLoadImage("12.png");	//載入　　圖片
	    			break;
	    		}
	    	case 13:
	    		{	C4 = cvLoadImage("13.png");	//載入我方獅子圖片
	    			break;
	    		}
	    	case 14:
	    		{	C4 = cvLoadImage("14.png");	//載入　　圖片
	    			break;
	    		}
	    	case 15:
	    		{	C4 = cvLoadImage("15.png");	//載入我方獅子圖片
	    			break;
	    		}
	    }
	    

	    cursor=cvLoadImage("cursor.png");
	    
		mask=cvLoadImage("1.png",0);	//載入灰階圖片 
		mask1=cvLoadImage("cursor.png",0);
		mask2=cvLoadImage("0.png",0);

		cvThreshold(mask,mask,250,255,CV_THRESH_BINARY_INV);
		cvThreshold(mask1,mask1,254,255,CV_THRESH_BINARY_INV);
		cvThreshold(mask2,mask2,254,255,CV_THRESH_BINARY_INV);
	
		

			while(kbhit())			//判斷鍵盤是否有被按下
		    {
			               
		    	directKey=getch();		//讀取鍵盤輸入字元  
				switch(directKey)
		        {
		        	case 56:	//向上移動;鍵盤輸入8 
		        		if(cursit % 4 != 0 && cursit > 1)
							cursit -= 1;
			            break;
			            
		        	case 50:	//向下移動;鍵盤輸入2 
		        		if(cursit != 3 && cursit % 4 != 3 && cursit < 18)
							cursit += 1;
			            break;
			            
		        	case 52:   //向左移動;鍵盤輸入4 
						if(cursit > 6 && cursit < 16)
							cursit -= 4;
						else if( cursit > 3 || cursit > 15 && cursit < 19)
							cursit -= 3;	
			            break;
		            
		            case 54:   //向右移動;鍵盤輸入6	
						if(cursit > 3 && cursit < 13)
							cursit += 4;
						else if( cursit > 0 && cursit < 4 || cursit > 12 && cursit < 16)
							cursit += 3;
						break;		
					
					case 53:	//選擇;鍵盤輸入5 
						if(temp[0]==0)
						{
							temp[0] = curindex(); 
							temp[1] = cursit; 
						}
						else
						{							
							chessman[chessY(temp[1])][chessX(temp[1])] = 0 ;
							chessman[chessY(cursit)][chessX(cursit)] = temp[0];
							temp[0] = 0 ;
							temp[1] = 0 ;				
						}
					
						
		        }
			}
			
			
	/***********************************************************************************************************************************************************/

		cvSetImageROI(map,cvRect(A1x,A1y,A1->width,A1->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[0][0] == 0)
		cvCopy(A1,map,mask2);
		else 
		cvCopy(A1,map,mask);	//將圖複製到感興區域 
		cvResetImageROI(map);	//釋放感興區域  

		cvSetImageROI(map,cvRect(A2x,A2y,A2->width,A2->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[1][0] == 0)
		cvCopy(A2,map,mask2);
		else 
		cvCopy(A2,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
	
		cvSetImageROI(map,cvRect(A3x,A3y,A3->width,A3->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[2][0] == 0)
		cvCopy(A3,map,mask2);
		else 
		cvCopy(A3,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(A4x,A4y,A4->width,A4->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[3][0] == 0)
		cvCopy(A4,map,mask2);
		else 
		cvCopy(A4,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(B1x,B1y,B1->width,B1->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[0][1] == 0)
		cvCopy(B1,map,mask2);
		else 
		cvCopy(B1,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(B2x,B2y,B2->width,B2->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[1][1] == 0)
		cvCopy(B2,map,mask2);
		else
		cvCopy(B2,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(B3x,B3y,B3->width,B3->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[2][1] == 0)
		cvCopy(B3,map,mask2);
		else 
		cvCopy(B3,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(B4x,B4y,B4->width,B4->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[3][1] == 0)
		cvCopy(B4,map,mask2);
		else 
		cvCopy(B4,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
	
		cvSetImageROI(map,cvRect(C1x,C1y,C1->width,C1->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[0][2] == 0)
		cvCopy(C1,map,mask2);
		else 
		cvCopy(C1,map,mask);	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(C2x,C2y,C2->width,C2->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[1][2] == 0)
		cvCopy(C2,map,mask2);
		else 
		cvCopy(C2,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(C3x,C3y,C3->width,C3->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[2][2] == 0)
		cvCopy(C3,map,mask2);
		else 
		cvCopy(C3,map,mask);	//將圖複製到感興區域 	//將圖複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		cvSetImageROI(map,cvRect(C4x,C4y,C4->width,C4->height));	//設置感興區域 (感興區圖MAP的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		if (chessman[3][2] == 0)
		cvCopy(C4,map,mask2);
		else
		cvCopy(C4,map,mask);	//將圖複製到感興區域 	//將圖B複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域 
		
		//cursor
		switch(cursit)
	    {
	    	case 1:
	    		{
	    			x = L1x-14; y = L1y-14;
	    			break;
	    		}
	    	case 2:
				{
					x = L2x-14; y = L2y-14;
					break;
				}	
			case 3:
				{
					x = L3x-14; y = L3y-14;
					break;
				}	
	    	case 4:
	    		{	x = A1x-14; y = A1y-14;
	    			break;
	    		}
	    	case 5:
	    		{	x = A2x-14; y = A2y-14;
	    			break;
	    		}
	    	case 6:
	    		{	x = A3x-14; y = A3y-14;
	    			break;
	    		}
	    	case 7:
	    		{	x = A4x-14; y = A4y-14;
	    			break;
	    		}
	    	case 8:
	    		{	x = B1x-14; y = B1y-14;
	    			break;
	    		}
	    	case 9:
	    		{	x = B2x-14; y = B2y-14;
	    			break;
	    		}
			case 10:
	    		{	x = B3x-14; y = B3y-14;
	    			break;
	    		}
	    	case 11:
	    		{	x = B4x-14; y = B4y-14;
	    			break;
	    		}
	    	case 12:
	    		{	x = C1x-14; y = C1y-14;
	    			break;
	    		}
	    	case 13:
	    		{	x = C2x-14; y = C2y-14;
	    			break;
	    		}
	    	case 14:
	    		{	x = C3x-14; y = C3y-14;
	    			break;
	    		}
	    	case 15:
	    		{	x = C4x-14; y = C4y-14;
	    			break;
	    		}
	    	case 16:
	    		{	x = R2x-14; y = R2y-14;
	    			break;
	    		}
	    	case 17:
	    		{	x = R3x-14; y = R3y-14;
	    			break;
	    		}	
	    	case 18:
	    		{	x = R4x-14; y = R4y-14;
	    			break;
	    		}	
	    }
		cvSetImageROI(map,cvRect(x,y,cursor->width,cursor->height));	//設置感興區域 (感興區圖1的一部份,(起域為始X座標,起始y做標,圖2寬度,圖2高度)) 
		cvCopy(cursor,map,mask1);	//將圖cursor複製到感興區域 	
		cvResetImageROI(map);	//釋放感興區域
		
		cvShowImage("LET'S CATHE THE LION!",map);	//顯示視窗 
    	cvWaitKey(1);	//延遲 
    	cvReleaseImage(&map); //清除IplImage圖形資料結構記憶體
    	cvReleaseImage(&A1);
    	cvReleaseImage(&A2);
    	cvReleaseImage(&A3);
    	cvReleaseImage(&A4);
    	cvReleaseImage(&B1);
    	cvReleaseImage(&B2);
    	cvReleaseImage(&B3);
    	cvReleaseImage(&B4);
    	cvReleaseImage(&C1);
    	cvReleaseImage(&C2);
    	cvReleaseImage(&C3);
    	cvReleaseImage(&C4);
    	cvReleaseImage(&cursor);
    	cvReleaseImage(&Blank);
    	cvReleaseImage(&mask);
    	cvReleaseImage(&mask1);
    	cvReleaseImage(&mask2);
    	
    }while(directKey!=17);
}

