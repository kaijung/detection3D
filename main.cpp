/***mages.push_back("./input/cup_c2/(1).png");
***********************************************************************************************
 **************************************************************************************************
 
     BSD 3-Clause License (https://www.tldrlegal.com/l/bsd3)
     Copyright (c) 2014 Andrés Solís Montero <http://www.solism.ca>, All rights reserved.
     
     
     Redistribution and use in source and binary forms, with or without modification,
     are permitted provided that the following conditions are met:
     
     1. Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
     2. Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the documentation
        and/or other materials provided with the distribution.
     3. Neither the name of the copyright holder nor the names of its contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.
     
     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
     AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
     IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
     ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
     LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
     DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
     THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
     OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
     OF THE POSSIBILITY OF SUCH DAMAGE.
 
 **************************************************************************************************
 **************************************************************************************************/

#include "objectdetector.h"
#include <stdio.h>
#include <sstream>  
string int2str( int val );
int str2int( const string &val );

using namespace viva;
/*
 *  3D object recognition and localization using an uncalibrated camera
 */
int main(int argc, const char * argv[])
{
    int i;
    char str[50];

    vector<string> images;
    Feat::Code feat;
    Desc::Code desc;
    //images.push_back("model.bmp");
	if (argc != 9){
	    printf("\nUsage:\n\t./detection3D <Feat> <Desc> <imgs.folder> <img.amount> <img.type> <webcam.width> <webam.height> <outputvideo.name>\n\t./detection3D ORB FREAK ./input/example/ 8 png 2304 1536 demo.avi\n\tFeat:\t1:ORB\t2:FAST\t3:MSER\t4:SIFT\t5:SURF\t6:STAR\t7:GRIDFAST\t8:GRIDORB\t9:RFAST\tDefault:RFAST\n\tDesc:\t1:ORB\t2:BRIEF\t3:SIFT\t4:SURF\t5:FREAK\t6:BRISK\tDefault:BRIEF\n");
	    return EXIT_FAILURE;
	}
    sprintf(str,"%s",argv[1]);
    switch( str )
    {
        case '1':
	    feat = Feat::ORB;
	    break;          
	case '2':
	    feat = Feat::FAST;
            break;
	case '3':
            feat = Feat::MSER;
            break;
        case '4':
            feat = Feat::SIFT;
            break;
        case '5':
            feat = Feat::SURF;
            break;
        case '6':
            feat = Feat::STAR;
            break;
        case '7':
            feat = Feat::GRIDFAST;
            break;
        case '8':
            feat = Feat::GRIDORB;
            break;
        case '9':
            feat = Feat::RFAST;
            break;
        default:
            feat = Feat::RFAST;
    }
    sprintf(str,"%s",argv[2]);
    switch(str )
    {
        case 1:
            desc = Desc::ORB;
            break;
        case 2:
            desc = Desc::BRIEF;
            break;
        case 3:
            desc = Desc::SIFT;
            break;
        case 4:
            desc = Desc::SURF;
            break;
        case 5:
            desc = Desc::FREAK;
            break;
        case '6':
            desc = Desc::BRISK;
            break;
        default:
            desc = Desc::BRIEF;
    }


//    Feat::Code feat = Feat::RFAST;
//    Desc::Code desc = Desc::BRIEF;
    for(i=1;i<str2int(argv[4]);i++)
    {
	sprintf(str,"%s%d.%s",argv[3],i,argv[5]);
	images.push_back(str);
    }



//    images.push_back("./input/cup_c2/(1).png");
//    images.push_back("./input/cup_c2/(2).png");
//    images.push_back("./input/cup_c2/(3).png");
//    images.push_back("./input/cup_c2/(4).png");
//    images.push_back("./input/cup_c2/(5).png");
//    images.push_back("./input/cup_c2/(6).png");
//    images.push_back("./input/cup_c2/(7).png");
//    images.push_back("./input/cup_c2/(8).png");

//    images.push_back("./input/cup_c/(1).jpg");
//    images.push_back("./input/cup_c/(2).jpg");
//    images.push_back("./input/cup_c/(3).jpg");
//    images.push_back("./input/cup_c/(4).jpg");
//    images.push_back("./input/cup_c/(5).jpg");
//    images.push_back("./input/cup_c/(6).jpg");
//    images.push_back("./input/cup_c/(7).jpg");
//    images.push_back("./input/cup_c/(8).jpg");

//    images.push_back("./input/cup/(1).jpg");
//    images.push_back("./input/cup/(2).jpg");
//    images.push_back("./input/cup/(3).jpg");
//    images.push_back("./input/cup/(4).jpg");
//    images.push_back("./input/cup/(5).jpg");
//    images.push_back("./input/cup/(6).jpg");
//    images.push_back("./input/cup/(7).jpg");
//    images.push_back("./input/cup/(8).jpg");
//    images.push_back("./input/cup/(9).jpg");


//    images.push_back("./input/cup/cup.jpeg"); 

//    images.push_back("./input/mix/01.jpg");
//    images.push_back("./input/mix/02.jpg");
//    images.push_back("./input/mix/03.jpg");
//    images.push_back("./input/mix/04.jpg");
//    images.push_back("./input/mix/05.jpg");
//    images.push_back("./input/mix/06.jpg");
//    images.push_back("./input/mix/07.jpg");
//    images.push_back("./input/mix/08.jpg");
//    images.push_back("./input/mix/09.jpg");
//    images.push_back("./input/mix/10.jpg");
//    images.push_back("./input/mix/11.jpg");
//    images.push_back("./input/mix/12.jpg");
//    images.push_back("./input/mix/13.jpg");
//    images.push_back("./input/mix/14.jpg");
//    images.push_back("./input/mix/15.jpg");
//    images.push_back("./input/mix/16.jpg");
//    images.push_back("./input/mix/17.jpg");
//    images.push_back("./input/mix/18.jpg");
//    images.push_back("./input/mix/19.jpg");
//    images.push_back("./input/mix/20.jpg");
//    images.push_back("./input/mix/21.jpg");
//    images.push_back("./input/mix/22.jpg");
//    images.push_back("./input/mix/23.jpg");
//    images.push_back("./input/mix/24.jpg");
//    images.push_back("./input/mix/25.jpg");
//    images.push_back("./input/mix/26.jpg");
//    images.push_back("./input/mix/27.jpg");
//    images.push_back("./input/mix/28.jpg");
//    images.push_back("./input/mix/29.jpg");
//    images.push_back("./input/mix/30.jpg");
//    images.push_back("./input/mix/31.jpg");
//    images.push_back("./input/mix/32.jpg");
//    images.push_back("./input/mix/33.jpg");
//    images.push_back("./input/mix/34.jpg");
//    images.push_back("./input/mix/35.jpg");

//    images.push_back("./input/cup/cup.jpeg");
//    images.push_back("./input/cup/ (1).jpg");
//    images.push_back("./input/cup/ (2).jpg");
//    images.push_back("./input/cup/ (3).jpg");
//    images.push_back("./input/cup/ (4).jpg");
//    images.push_back("./input/cup/ (5).jpg");
//    images.push_back("./input/cup/ (6).jpg");
//    images.push_back("./input/cup/ (7).jpg");
//    images.push_back("./input/cup/ (8).jpg");
//    images.push_back("./input/cup/ (9).jpg");
//    images.push_back("./input/cup/ (10).jpg");
//    images.push_back("./input/cup/ (11).jpg");
//    images.push_back("./input/cup/ (12).jpg");
//    images.push_back("./input/cup/ (13).jpg");
//    images.push_back("./input/cup/ (14).jpg");
//    images.push_back("./input/cup/ (15).jpg");
//    images.push_back("./input/cup/ (16).jpg");

//    images.push_back("./input/cup.orot/02.jpg");
//    images.push_back("./input/cup.orot/06.jpg");
//    images.push_back("./input/cup.orot/10.jpg");
//    images.push_back("./input/cup.orot/14.jpg");
//    images.push_back("./input/cup.orot/18.jpg");

//    images.push_back("./input/cup.nrot/02.jpg");
//    images.push_back("./input/cup.nrot/06.jpg");
//    images.push_back("./input/cup.nrot/10.jpg");
//    images.push_back("./input/cup.nrot/14.jpg");
//    images.push_back("./input/cup.nrot/18.jpg");
    
//    images.push_back("./input/car01/01.jpg");
//    images.push_back("./input/car01/02.jpg");
//    images.push_back("./input/car01/03.jpg");
//    images.push_back("./input/car01/04.jpg");
//    images.push_back("./input/car01/05.jpg");
//    images.push_back("./input/car01/06.jpg");
    
//    images.push_back("./input/car02/01.jpg");
//    images.push_back("./input/car02/02.jpg");
//    images.push_back("./input/car02/03.jpg");
//    images.push_back("./input/car02/04.jpg");
//    images.push_back("./input/car02/05.jpg");
//    images.push_back("./input/car02/06.jpg");
//    images.push_back("./input/car02/07.jpg");
//    images.push_back("./input/car02/08.jpg");
    
//    images.push_back("./input/car03/01.jpg");
//    images.push_back("./input/car03/02.jpg");
//    images.push_back("./input/car03/03.jpg");
//    images.push_back("./input/car03/04.jpg");
//    images.push_back("./input/car03/05.jpg");
//    images.push_back("./input/car03/06.jpg");
//    images.push_back("./input/car03/07.jpg");
//    images.push_back("./input/car03/08.jpg");
//    images.push_back("./input/car03/09.jpg");

//    images.push_back("./input/toy/01.jpg");
//    images.push_back("./input/toy/02.jpg");
//    images.push_back("./input/toy/03.jpg");
//    images.push_back("./input/toy/04.jpg");
//    images.push_back("./input/toy/05.jpg");
//    images.push_back("./input/toy/06.jpg");
//    images.push_back("./input/toy/07.jpg");
    

    Ptr<Input> input = new CameraInput(0, Size(str2int(argv[6]),str2int(argv[7])));

    Ptr<ProcessFrame> process = new ObjectDetector(images, feat, desc);
    sprintf(str,"%s",argv[8]);
    Ptr<Output> output = new VideoOutput(str,Size(str2int(argv[6]),str2int(argv[7])));
    //1920,1080
    //2304,1536
    Processor processor;
    processor.setInput(input);
    processor.setProcess(process);
    processor.setOutput(output);
    processor.run();
    
    return 0;
}
string int2str( int val )  
{  
    ostringstream out;  
    out<<val;  
    return out.str();  
}

int str2int( const string &val )  
{  
    istringstream in(val.c_str());
    int ret = 0;  
    in >> ret;  
    return ret;  
}    
