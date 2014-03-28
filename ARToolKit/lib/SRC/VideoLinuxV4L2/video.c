/* 
 *   Video capture subrutine for Linux/Video4Linux2 devices 
 *   Based upon the V4L 1 artoolkit code and v4l2 spec example 
 *   at http://v4l2spec.bytesex.org/spec/a13010.htm
 *   Simon Goodall <sg@ecs.soton.ac.uk>
 */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <linux/types.h>
#include <linux/videodev2.h>
#include <AR/video.h>
#include "ccvt.h"

#define MAXCHANNEL   10

static AR2VideoParamT   *gVid = NULL;

static void printPalette(int p) {
  switch(p) {
//YUV formats
    case (V4L2_PIX_FMT_GREY): printf("  Pix Fmt: Grey\n"); break;
    case (V4L2_PIX_FMT_YUYV): printf("  Pix Fmt: YUYV-zhezhezhezhe\n"); break;
    case (V4L2_PIX_FMT_UYVY): printf("  Pix Fmt: UYVY-lalalalalla\n"); break;
    case (V4L2_PIX_FMT_Y41P): printf("  Pix Fmt: Y41P\n"); break;
    case (V4L2_PIX_FMT_YVU420): printf("  Pix Fmt: YVU420\n"); break;
    case (V4L2_PIX_FMT_YVU410): printf("  Pix Fmt: YVU410\n"); break;
    case (V4L2_PIX_FMT_YUV422P): printf("  Pix Fmt: YUV422P\n"); break;
    case (V4L2_PIX_FMT_YUV411P): printf("  Pix Fmt: YUV411P\n"); break;
    case (V4L2_PIX_FMT_NV12): printf("  Pix Fmt: NV12\n"); break;
    case (V4L2_PIX_FMT_NV21): printf("  Pix Fmt: NV21\n"); break;
// RGB formats 
    case (V4L2_PIX_FMT_RGB332): printf("  Pix Fmt: RGB332\n"); break;
    case (V4L2_PIX_FMT_RGB555): printf("  Pix Fmt: RGB555\n"); break;
    case (V4L2_PIX_FMT_RGB565): printf("  Pix Fmt: RGB565\n"); break;
    case (V4L2_PIX_FMT_RGB555X): printf("  Pix Fmt: RGB555X\n"); break;
    case (V4L2_PIX_FMT_RGB565X): printf("  Pix Fmt: RGB565X\n"); break;
    case (V4L2_PIX_FMT_BGR24): printf("  Pix Fmt: BGR24\n"); break;
    case (V4L2_PIX_FMT_RGB24): printf("  Pix Fmt: RGB24\n"); break;
    case (V4L2_PIX_FMT_BGR32): printf("  Pix Fmt: BGR32\n"); break;
    case (V4L2_PIX_FMT_RGB32): printf("  Pix Fmt: RGB32\n"); break;
  };

}

static int getControl(int fd, int type, int *value) {
  struct v4l2_queryctrl queryctrl;
  struct v4l2_control control;

  memset (&queryctrl, 0, sizeof (queryctrl));
  // TODO: Manke sure this is a correct value
  queryctrl.id = type;

  if (-1 == ioctl (fd, VIDIOC_QUERYCTRL, &queryctrl)) {
    if (errno != EINVAL) {
      fprintf(stderr, "Error calling VIDIOC_QUERYCTRL\n");
      return 1;
     } else {
       printf ("Control %d is not supported\n", type);
       return 1;
     }
   } else if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED) {
     printf ("Control %s is not supported\n", queryctrl.name);
     return 1;
   } else {
     memset (&control, 0, sizeof (control));
     control.id = type;

     if (-1 == ioctl (fd, VIDIOC_G_CTRL, &control)) {
       fprintf(stderr, "Error getting control %s value\n", queryctrl.name);
       return 1;
     }
     *value = control.value;
  }
  return 0;
}


static int setControl(int fd, int type, int value) {
  struct v4l2_queryctrl queryctrl;
  struct v4l2_control control;

  memset (&queryctrl, 0, sizeof (queryctrl));
  // TODO: Manke sure this is a correct value
  queryctrl.id = type;

  if (-1 == ioctl (fd, VIDIOC_QUERYCTRL, &queryctrl)) {
    if (errno != EINVAL) {
      fprintf(stderr, "Error calling VIDIOC_QUERYCTRL\n");
      return 1;
     } else {
       printf ("Control %d is not supported\n", type);
       return 1;
     }
   } else if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED) {
     printf ("Control %s is not supported\n", queryctrl.name);
     return 1;
   } else {
     memset (&control, 0, sizeof (control));
     control.id = type;
     // TODO check min/max range
     // If value is -1, then we use the default value
     control.value = (value == -1) ? (queryctrl.default_value) : (value);

     if (-1 == ioctl (fd, VIDIOC_S_CTRL, &control)) {
       fprintf(stderr, "Error setting control %s to %d\n", queryctrl.name, value);
       return 1;
     }
  }
  return 0;
}

int arVideoDispOption( void )
{
    return  ar2VideoDispOption();
}

int arVideoOpen( char *config )
{
    if( gVid != NULL ) {
        printf("Device has been opened!!\n");
        return -1;
    }
    gVid = ar2VideoOpen( config );
    if( gVid == NULL ) return -1;

    return 0;
}

int arVideoClose( void )
{
    int result;
	
    if( gVid == NULL ) return -1;

	result = ar2VideoClose(gVid);
	gVid = NULL;
    return (result);
}

int arVideoInqSize( int *x, int *y )
{
    if( gVid == NULL ) return -1;

    return ar2VideoInqSize( gVid, x, y );
}

ARUint8 *arVideoGetImage( void )
{
    if( gVid == NULL ) return NULL;

    return ar2VideoGetImage( gVid );
}

int arVideoCapStart( void )
{
    if( gVid == NULL ) return -1;

    return ar2VideoCapStart( gVid );
}

int arVideoCapStop( void )
{
    if( gVid == NULL ) return -1;

    return ar2VideoCapStop( gVid );
}

int arVideoCapNext( void )
{
    if( gVid == NULL ) return -1;

    return ar2VideoCapNext( gVid );
}

/*-------------------------------------------*/

int ar2VideoDispOption( void )
{
    printf("ARVideo may be configured using one or more of the following options,\n");
    printf("separated by a space:\n\n");
    printf("DEVICE CONTROLS:\n");
    printf(" -dev=filepath\n");
    printf("    specifies device file.\n");
    printf(" -channel=N\n");
    printf("    specifies source channel.\n");
    printf(" -width=N\n");
    printf("    specifies expected width of image.\n");
    printf(" -height=N\n");
    printf("    specifies expected height of image.\n");
    printf(" -palette=[RGB|YUV420P]\n");
    printf("    specifies the camera palette (WARNING:all are not supported on each camera !!).\n");
    printf("IMAGE CONTROLS (WARNING: every options are not supported by all camera !!):\n");
    printf(" -brightness=N\n");
    printf("    specifies brightness. (0.0 <-> 1.0)\n");
    printf(" -contrast=N\n");
    printf("    specifies contrast. (0.0 <-> 1.0)\n");
    printf(" -saturation=N\n");
    printf("    specifies saturation (color). (0.0 <-> 1.0) (for color camera only)\n");    
    printf(" -hue=N\n");
    printf("    specifies hue. (0.0 <-> 1.0) (for color camera only)\n");    
    printf("OPTION CONTROLS:\n");
    printf(" -mode=[PAL|NTSC|SECAM]\n");
    printf("    specifies TV signal mode (for tv/capture card).\n");
    printf("\n");

    return 0;
}

AR2VideoParamT *ar2VideoOpen( char *config_in )
{

// Warning, this function leaks badly when an error occurs.
    AR2VideoParamT            *vid;
    struct v4l2_capability   vd;
    struct v4l2_format fmt;
    struct v4l2_input  ipt;
    struct v4l2_requestbuffers req;

    char                      *config, *a, line[256];
    int value;

    /* If no config string is supplied, we should use the environment variable, otherwise set a sane default */
    if (!config_in || !(config_in[0])) {
        /* None suppplied, lets see if the user supplied one from the shell */
        char *envconf = getenv ("ARTOOLKIT_CONFIG");
        if (envconf && envconf[0]) {
            config = envconf;
            printf ("Using config string from environment [%s].\n", envconf);
        } else {
            config = NULL;
            printf ("No video config string supplied, using defaults.\n");
        }
    } else {
        config = config_in;
        printf ("Using supplied video config string [%s].\n", config_in);
    }

    arMalloc( vid, AR2VideoParamT, 1 );
    strcpy( vid->dev, DEFAULT_VIDEO_DEVICE );
    vid->width      = DEFAULT_VIDEO_WIDTH;
    vid->height     = DEFAULT_VIDEO_HEIGHT;
    vid->palette = V4L2_PIX_FMT_YUYV;     /* palette format */
    vid->contrast   = -1;
    vid->brightness = -1;
    vid->saturation = -1;
    vid->hue        = -1;
    vid->gamma  = -1;
    vid->exposure  = -1;
    vid->gain  = -1;
    vid->mode       = V4L2_STD_NTSC;
    //vid->debug      = 0;
    vid->debug      = 1;
    vid->channel = 0;
    vid->videoBuffer=NULL;

    a = config;
    if( a != NULL) {
        for(;;) {
            while( *a == ' ' || *a == '\t' ) a++;
            if( *a == '\0' ) break;
            if( strncmp( a, "-dev=", 5 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[5], "%s", vid->dev ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-channel=", 9 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[9], "%d", &vid->channel ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-width=", 7 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[7], "%d", &vid->width ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-height=", 8 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[8], "%d", &vid->height ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-palette=", 9 ) == 0 ) {
                if( strncmp( &a[9], "GREY", 4) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_GREY;
                } else if( strncmp( &a[9], "HI240", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_HI240;
                } else if( strncmp( &a[9], "RGB565", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_RGB565;
                } else if( strncmp( &a[9], "RGB555", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_RGB555;
                } else if( strncmp( &a[9], "BGR24", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_BGR24;
                } else if( strncmp( &a[9], "BGR32", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_BGR32;
                } else if( strncmp( &a[9], "YUYV", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_YUYV;
                } else if( strncmp( &a[9], "UYVY", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_UYVY;
                } else if( strncmp( &a[9], "Y41P", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_Y41P;
                } else if( strncmp( &a[9], "YUV422P", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_YUV422P;
                } else if( strncmp( &a[9], "YUV411P", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_YUV411P;
                } else if( strncmp( &a[9], "YVU420", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_YVU420;
                } else if( strncmp( &a[9], "YVU410", 3) == 0 ) {
                  vid->palette = V4L2_PIX_FMT_YVU410;
		}
            }
            else if( strncmp( a, "-contrast=", 10 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[10], "%d", &vid->contrast ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-brightness=", 12 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[12], "%d", &vid->brightness ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-saturation=", 12 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[12], "%d", &vid->saturation ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }	    
            else if( strncmp( a, "-hue=", 5 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[5], "%d", &vid->hue ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }	
	    else if( strncmp( a, "-gamma=", 7 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[7], "%d", &vid->gamma ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-exposure=", 10 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[10], "%d", &vid->exposure ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
             else if( strncmp( a, "-gain=", 6 ) == 0 ) {
                sscanf( a, "%s", line );
                if( sscanf( &line[6], "%d", &vid->gain ) == 0 ) {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-mode=", 6 ) == 0 ) {
                if( strncmp( &a[6], "PAL", 3 ) == 0 )        vid->mode = V4L2_STD_PAL;
                else if( strncmp( &a[6], "NTSC", 4 ) == 0 )  vid->mode = V4L2_STD_NTSC;
                else if( strncmp( &a[6], "SECAM", 5 ) == 0 ) vid->mode = V4L2_STD_SECAM;
                else {
                    ar2VideoDispOption();
                    free( vid );
                    return 0;
                }
            }
            else if( strncmp( a, "-debug", 6 ) == 0 ) {
                vid->debug = 1;
            }
            else {
                ar2VideoDispOption();
                free( vid );
                return 0;
            }

            while( *a != ' ' && *a != '\t' && *a != '\0') a++;
        }
    }

    vid->fd = open(vid->dev, O_RDWR);// O_RDONLY ?
    if(vid->fd < 0){
        printf("video device (%s) open failed\n",vid->dev); 
        free( vid );
        return 0;
    }

    if(ioctl(vid->fd,VIDIOC_QUERYCAP,&vd) < 0){
        printf("ioctl failed\n");
        free( vid );
        return 0;
    }

    if (!(vd.capabilities & V4L2_CAP_STREAMING)) {
      fprintf (stderr, "Device does not support streaming i/o\n");
    }

    if(vid->debug ) {
        printf("=== debug info! ===\n");
        printf("  vd.driver        =   %s\n",vd.driver);
        printf("  vd.card          =   %s\n",vd.card);
        printf("  vd.bus_info      =   %s\n",vd.bus_info);
        printf("  vd.version       =   %d\n",vd.version);
        printf("  vd.capabilities  =   %d\n",vd.capabilities);
    }

    memset(&fmt, 0, sizeof(fmt));

    fmt.type                = V4L2_BUF_TYPE_VIDEO_CAPTURE;
#if 1
	printf("----custom----");
    fmt.fmt.pix.width       = vid->width; 
    fmt.fmt.pix.height      = vid->height;
    fmt.fmt.pix.pixelformat = vid->palette;
    fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
	printf("-------");
#else
	printf("----moren----");
    fmt.fmt.pix.width       = 720; 
    fmt.fmt.pix.height      = 288;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;
    fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;
	printf("-------");
#endif

    if (ioctl (vid->fd, VIDIOC_S_FMT, &fmt) < 0) {
      close(vid->fd);
      free( vid );
      printf("ar2VideoOpen: Error setting video format (%d)\n", errno);
      return 0;
    }
    vid->palette = fmt.fmt.pix.pixelformat;
    vid->width = fmt.fmt.pix.width;
    vid->height = fmt.fmt.pix.height;

    if (vid->debug) {
      printf("  Width: %d\n", fmt.fmt.pix.width);
      printf("  Height: %d\n", fmt.fmt.pix.height);
      printPalette(fmt.fmt.pix.pixelformat);
    }
  
    memset(&ipt, 0, sizeof(ipt));

    ipt.index = vid->channel;
    ipt.std = vid->mode;

    if(ioctl(vid->fd,VIDIOC_ENUMINPUT,&ipt) < 0) {	
      printf("arVideoOpen: Error querying input device type\n");
      close(vid->fd);
      free( vid );
      return 0;
    }

    if (vid->debug) {
      if (ipt.type == V4L2_INPUT_TYPE_TUNER) {
        printf("  Type: Tuner\n");
      } 
      if (ipt.type == V4L2_INPUT_TYPE_CAMERA) {
        printf("  Type: Camera\n");
      }
    }
   
    // Set channel
    if (ioctl(vid->fd, VIDIOC_S_INPUT, &ipt)) {
      printf("arVideoOpen: Error setting video input\n");
      close(vid->fd);
      free( vid );
      return 0;
    } 


    // Attempt to set some camera controls
    setControl(vid->fd, V4L2_CID_BRIGHTNESS, vid->brightness);
    setControl(vid->fd, V4L2_CID_CONTRAST, vid->contrast);
    setControl(vid->fd, V4L2_CID_SATURATION, vid->saturation);
    setControl(vid->fd, V4L2_CID_HUE, vid->hue);
    setControl(vid->fd, V4L2_CID_GAMMA, vid->gamma);
    setControl(vid->fd, V4L2_CID_EXPOSURE, vid->exposure);
    setControl(vid->fd, V4L2_CID_GAIN, vid->gain);

    // Print out current control values
    if(vid->debug ) {
      if (!getControl(vid->fd, V4L2_CID_BRIGHTNESS, &value)) {
        printf("Brightness: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_CONTRAST, &value)) {
        printf("Contrast: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_SATURATION, &value)) {
        printf("Saturation: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_HUE, &value)) {
        printf("Hue: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_GAMMA, &value)) {
        printf("Gamma: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_EXPOSURE, &value)) {
        printf("Exposure: %d\n", value);
      }
      if (!getControl(vid->fd, V4L2_CID_GAIN, &value)) {
        printf("Gain: %d\n", value);
      }
    }

//    if (vid->palette==V4L2_PIX_FMT_YUYV)
  arMalloc( vid->videoBuffer, ARUint8, vid->width*vid->height*3 );

  // Setup memory mapping
  memset(&req, 0, sizeof(req));
  req.count = 2;
  req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  req.memory = V4L2_MEMORY_MMAP;

  if (ioctl(vid->fd, VIDIOC_REQBUFS, &req)) {
    printf("Error calling VIDIOC_REQBUFS\n");
      close(vid->fd);
      if(vid->videoBuffer!=NULL) free(vid->videoBuffer);
      free( vid );
    return 0;
  }

  if (req.count < 2) {
    printf("this device can not be supported by libARvideo.\n");
    printf("(req.count < 2)\n");
      close(vid->fd);
      if(vid->videoBuffer!=NULL) free(vid->videoBuffer);
      free( vid );

    return 0;
  }
   
  vid->buffers = (struct buffer*)calloc(req.count , sizeof(*vid->buffers));

  if (vid->buffers == NULL ) {
    printf("ar2VideoOpen: Error allocating buffer memory\n");
    close(vid->fd);
    if(vid->videoBuffer!=NULL) free(vid->videoBuffer);
    free( vid );
    return 0;
  }

  for (vid->n_buffers = 0; vid->n_buffers < req.count; ++vid->n_buffers) {
    struct v4l2_buffer buf;
    memset(&buf, 0, sizeof(buf));
    buf.type        = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory      = V4L2_MEMORY_MMAP;
    buf.index       = vid->n_buffers;

    if (ioctl (vid->fd, VIDIOC_QUERYBUF, &buf)) {
      printf ("error VIDIOC_QUERYBUF\n");
      close(vid->fd);
      if(vid->videoBuffer!=NULL) free(vid->videoBuffer);
      free( vid );
      return 0;
    }

    vid->buffers[vid->n_buffers].length = buf.length;
    vid->buffers[vid->n_buffers].start =
      mmap (NULL /* start anywhere */,
            buf.length,
            PROT_READ | PROT_WRITE /* required */,
            MAP_SHARED /* recommended */,
            vid->fd, buf.m.offset);

    if (MAP_FAILED == vid->buffers[vid->n_buffers].start) {
      printf("Error mmap\n");
      close(vid->fd);
      if(vid->videoBuffer!=NULL) free(vid->videoBuffer);
      free( vid );
      return 0;
    }
  }

  vid->video_cont_num = -1;

  return vid;
}

int ar2VideoClose( AR2VideoParamT *vid )
{
    if(vid->video_cont_num >= 0){
        ar2VideoCapStop( vid );
    }
    close(vid->fd);
    if(vid->videoBuffer!=NULL)
        free(vid->videoBuffer);
    free( vid );

    return 0;
} 


int ar2VideoCapStart( AR2VideoParamT *vid )
{
  enum v4l2_buf_type type;
  struct v4l2_buffer buf;
  int i;

  if (vid->video_cont_num >= 0){
    printf("arVideoCapStart has already been called.\n");
    return -1;
  }

  vid->video_cont_num = 0;

  for (i = 0; i < vid->n_buffers; ++i) {
    memset(&buf, 0, sizeof(buf));
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = i;
    if (ioctl(vid->fd, VIDIOC_QBUF, &buf)) {
      printf("ar2VideoCapStart: Error calling VIDIOC_QBUF: %d\n", errno);
      return -1;
    }
  }

  type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  if (ioctl(vid->fd, VIDIOC_STREAMON, &type)) {
    printf("ar2VideoCapStart: Error calling VIDIOC_STREAMON\n");
    return -1;
  }

  return 0;
}

int ar2VideoCapNext( AR2VideoParamT *vid )
{
  struct v4l2_buffer buf;

  if (vid->video_cont_num < 0){
    printf("arVideoCapStart has never been called.\n");
    return -1;
  }

  memset(&buf, 0, sizeof(buf));
  buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  buf.memory = V4L2_MEMORY_MMAP;
  buf.index = vid->video_cont_num;

  if (ioctl(vid->fd, VIDIOC_QBUF, &buf)) {
    printf("ar2VideoCapNext: Error calling VIDIOC_QBUF: %d\n", errno);
    return 1;
  }

  return 0;
}

int ar2VideoCapStop( AR2VideoParamT *vid )
{
  enum v4l2_buf_type type;
  if(vid->video_cont_num < 0){
    printf("arVideoCapStart has never been called.\n");
    return -1;
  }

  type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

  if (ioctl(vid->fd, VIDIOC_STREAMOFF, &type)) {
    printf("Error calling VIDIOC_STREAMOFF\n");
    return -1;
  }

  vid->video_cont_num = -1;

  return 0;
}


ARUint8 *ar2VideoGetImage( AR2VideoParamT *vid )
{
    ARUint8 *buffer;
    struct v4l2_buffer buf;

    if(vid->video_cont_num < 0){
        printf("arVideoCapStart has never been called.\n");
        return NULL;
    }

    memset(&buf, 0, sizeof(buf));
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;

    if (ioctl(vid->fd, VIDIOC_DQBUF, &buf) < 0) {
      printf("Error calling VIDIOC_DQBUF: %d\n", errno);
      return NULL;
    }
    
    buffer = (ARUint8*)vid->buffers[buf.index].start;
    vid->video_cont_num = buf.index;

    // TODO: Add other video format conversions.
    if (vid->palette == V4L2_PIX_FMT_YUYV) {
#if defined(AR_PIX_FORMAT_BGRA)
      ccvt_yuyv_rgb32(vid->width, vid->height, buffer, vid->videoBuffer);
#else
      ccvt_yuyv_rgb24(vid->width, vid->height, buffer, vid->videoBuffer);
#endif
      return vid->videoBuffer;
    }
    if (vid->palette == V4L2_PIX_FMT_UYVY) {

      //ccvt_yuv_rgb(vid->width, vid->height, buffer, vid->videoBuffer);
        convert_yuv_to_rgb_buffer(vid->width, vid->height, buffer, vid->videoBuffer);
      return vid->videoBuffer;
    }

    return buffer;

}
void convert_yuv_to_rgb_buffer( unsigned int width, unsigned int height,unsigned char *yuv, unsigned char *rgb)
{
 unsigned int in, out = 0;
 unsigned int pixel_16;
 unsigned char pixel_24[3];
 unsigned int pixel32;
 int y0, u, y1, v;
 for(in = 0; in < width * height * 2; in += 4) {
  pixel_16 =
   yuv[in + 3] << 24 |//Y1
   yuv[in + 2] << 16 |//V
   yuv[in + 1] <<  8 |//Y0
   yuv[in + 0];//U
/*
  y0 = (pixel_16 & 0x000000ff);
  u  = (pixel_16 & 0x0000ff00) >>  8;
  y1 = (pixel_16 & 0x00ff0000) >> 16;
  v  = (pixel_16 & 0xff000000) >> 24;
*/
 /*UYVY格式转化*/
    u = (pixel_16 & 0x000000ff);
   y0 = (pixel_16 & 0x0000ff00)>>8;
    v = (pixel_16 & 0x00ff0000) >>16;
   y1 = (pixel_16 & 0xff000000) >> 24;
/**/
//printf("u:%d, y0:%d,v:%d,y1:%d\n",u,y0,v,y1);
  pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
//  printf("%d\t",pixel32);
  pixel_24[0] = (pixel32 & 0x000000ff);
  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
  rgb[out++] = pixel_24[0];
  rgb[out++] = pixel_24[1];
  rgb[out++] = pixel_24[2];
 // printf("R:%d,G:%d,B:%d\n",pixel_24[0],pixel_24[1],pixel_24[2]);

  pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
  pixel_24[0] = (pixel32 & 0x000000ff);
  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
  rgb[out++] = pixel_24[0];
  rgb[out++] = pixel_24[1];
  rgb[out++] = pixel_24[2];
//  printf("R:%d,G:%d,B:%d\n",pixel_24[0],pixel_24[1],pixel_24[2]);

 }

}
int convert_yuv_to_rgb_pixel(int y, int u, int v)
{
 unsigned int pixel32 = 0;
 unsigned char *pixel = (unsigned char *)&pixel32;
 int r, g, b;
 r = y + (1.370705 * (v-128));
 g = y - (0.698001 * (v-128)) - (0.337633 * (u-128));
 // g = y - 0.34413*(u-128) - 0.71414*(v -128);
 b = y + (1.732446 * (u-128));
 if(r > 255) r = 255;
 if(g > 255) g = 255;
 if(b > 255) b = 255;
 if(r < 0) r = 0;
 if(g < 0) g = 0;
 if(b < 0) b = 0;
 pixel[0] = r * 220 / 256;
 pixel[1] = g * 220 / 256;
 pixel[2] = b * 220 / 256;
 return pixel32;
}
int ar2VideoInqSize(AR2VideoParamT *vid, int *x,int *y)
{
  *x = vid->width;
  *y = vid->height;

  return 0;
}

