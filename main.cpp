/**************************************************************************************************
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
    if (argc != 9){
	printf("\nUsage:\n\t./detection3D <Feat> <Desc> <imgs.folder> <img.amount> <img.type> <webcam.width> <webam.height> <outputvideo.name>\n\t./detection3D RFAST BRIEF ./input/example/ 23 png 2304 1536 demo.avi\n\tFeat:ORB,FAST,MSER,SIFT,SURF,STAR,GRIDFAST,GRIDORB,RFAST,Default:RFAST\n\tDesc:ORB,BRIEF,SIFT,SURF,FREAK,BRISK,Default:BRIEF\n");
	    return EXIT_FAILURE;
	}
        
    if (strcmp(argv[1],"ORB")==0)
	feat = Feat::ORB;          
    else if (strcmp(argv[1],"FAST")==0||strcmp(argv[1],"fast")==0)
	feat = Feat::FAST;
    else if (strcmp(argv[1],"MSER")==0||strcmp(argv[1],"mser")==0)
        feat = Feat::MSER;
    else if (strcmp(argv[1],"SIFT")==0||strcmp(argv[1],"sift")==0)
        feat = Feat::SIFT;
    else if (strcmp(argv[1],"SURF")==0||strcmp(argv[1],"surf")==0)
        feat = Feat::SURF;
    else if (strcmp(argv[1],"STAR")==0||strcmp(argv[1],"star")==0)
        feat = Feat::STAR;
    else if (strcmp(argv[1],"GRIDFAST")==0||strcmp(argv[1],"gridfast")==0)
        feat = Feat::GRIDFAST;
    else if (strcmp(argv[1],"GRIDORB")==0||strcmp(argv[1],"gridorb")==0)
        feat = Feat::GRIDORB;
    else if (strcmp(argv[1],"RFAST")==0||strcmp(argv[1],"rfast")==0)
        feat = Feat::RFAST;
    else
        feat = Feat::RFAST;

    if(strcmp(argv[2],"ORB")==0||strcmp(argv[2],"orb")==0)
	desc = Desc::ORB;
    else if (strcmp(argv[2],"BRIEF")==0||strcmp(argv[2],"brief")==0)
        desc = Desc::BRIEF;
    else if (strcmp(argv[2],"SIFT")==0||strcmp(argv[2],"sift")==0)
        desc = Desc::SIFT;
    else if (strcmp(argv[2],"SURF")==0||strcmp(argv[2],"surf")==0)
        desc = Desc::SURF;
    else if (strcmp(argv[2],"FREAK")==0||strcmp(argv[2],"freak")==0)
        desc = Desc::FREAK;
    else if (strcmp(argv[2],"BRISK")==0||strcmp(argv[2],"brisk")==0)
        desc = Desc::BRISK;
    else
        desc = Desc::BRIEF;

//    feat = Feat::RFAST;
//    desc = Desc::BRIEF;
    for(i=1;i<=str2int(argv[4]);i++)
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
