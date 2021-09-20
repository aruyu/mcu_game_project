/*
        Image size            H = 20    V = 20

        Gray 2bit/pixel       Total : 100 x 6 Bytes
*/

const uint8_t charRun[6][100] PROGMEM = 
{
  {
    0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x0f,0xfc,0x00,
    0x00,0xf0,0xfa,0xab,0xc0,
    0x03,0xff,0xaa,0xaa,0xb0,
    0x03,0xea,0xaa,0xaa,0xac,
    0x00,0xfa,0xaa,0xaa,0xfc,
    0x00,0x0d,0x6a,0xaf,0xff,
    0x00,0x0d,0x5d,0x5f,0xff,
    0x00,0x03,0xd7,0xff,0x3c,
    0x00,0x00,0x35,0x57,0x3c,
    0x00,0x00,0xf5,0x57,0xfc,
    0x00,0x03,0xaa,0x57,0xf0,
    0x00,0x3e,0xaa,0x60,0x70,
    0x00,0xea,0xa9,0x80,0x70,
    0x03,0xaa,0xa9,0x80,0xc0,
    0x0e,0xaa,0x96,0x02,0xc0,
    0x0e,0x95,0x68,0x07,0x00,
    0x39,0x6a,0x80,0x03,0x00,
    0x0e,0xb5,0x50,0x03,0x00,
    0x03,0xcd,0x40,0x0c,0x00 
  },

  {
    0x00,0x00,0x00,0xff,0xc0,
    0x00,0x00,0x0f,0xaa,0xb0,
    0x00,0x00,0x3a,0xaa,0xac,
    0x00,0xf3,0xea,0xaa,0xfc,
    0x03,0xfe,0xaa,0xaa,0xff,
    0x03,0xea,0xaa,0xab,0xff,
    0x00,0xf5,0xaa,0x9f,0xfc,
    0x00,0x0d,0x55,0x5f,0x3c,
    0x00,0x03,0xf7,0x5f,0x3c,
    0x00,0x00,0x39,0xf7,0xf0,
    0x00,0x00,0xe9,0x54,0x70,
    0x00,0x03,0xaa,0x98,0x70,
    0x00,0x0e,0xaa,0x60,0xc0,
    0x00,0x3a,0xaa,0x60,0xc0,
    0x00,0xea,0xa9,0x80,0xc0,
    0x03,0xaa,0xa9,0x80,0xc0,
    0x0e,0xaa,0x96,0x00,0xc0,
    0x39,0x55,0x68,0xc3,0x00,
    0x0e,0xaa,0x83,0x3c,0x00,
    0x03,0xfc,0x0c,0x00,0x00 
  },

  {
    0x00,0x00,0x0f,0xff,0xf0,
    0x00,0x00,0x3a,0xaa,0xac,
    0x00,0x00,0xea,0xaa,0xff,
    0x00,0x03,0xaa,0xab,0xff,
    0x00,0x3f,0xaa,0xab,0xff,
    0x00,0xfe,0xaa,0xaf,0x3c,
    0x00,0xfa,0xaa,0xb7,0x3c,
    0x00,0x3d,0x55,0xd7,0xfc,
    0x00,0x03,0xd5,0xd7,0xf0,
    0x00,0x03,0xa9,0x54,0x70,
    0x00,0x0e,0xaa,0x60,0xb0,
    0x00,0x3a,0xa9,0x80,0xb0,
    0x00,0x3a,0xa6,0x02,0xb0,
    0x00,0xea,0xa6,0x02,0xc0,
    0x00,0xea,0x98,0x00,0xc0,
    0x00,0xea,0x98,0x00,0xc0,
    0x03,0x95,0x58,0xf0,0xc0,
    0x00,0xea,0xa3,0x0c,0xc0,
    0x00,0x3c,0x0c,0x03,0x00,
    0x00,0x03,0x30,0x00,0x00 
  },

  {
    0x00,0x00,0xff,0xff,0xc0,
    0x00,0x03,0xaa,0xaa,0xb0,
    0x00,0x0e,0xaa,0xaa,0xac,
    0x00,0x3a,0xaa,0xaa,0xff,
    0x00,0xea,0xaa,0xaf,0xff,
    0x03,0xe6,0xab,0xff,0xfc,
    0x03,0xfd,0x9f,0x57,0x3c,
    0x00,0xff,0x57,0x57,0x3c,
    0x00,0x0f,0xa5,0x57,0xfc,
    0x00,0x3a,0xa9,0x53,0xf0,
    0x00,0xea,0xa6,0x80,0xc0,
    0x03,0xaa,0x98,0x00,0xc0,
    0x03,0xaa,0x60,0x02,0xb0,
    0x0e,0xa9,0x80,0x02,0xb0,
    0x0d,0xa9,0x80,0x0a,0xb0,
    0x0e,0x69,0x80,0x02,0xc0,
    0x03,0x95,0x80,0x03,0x00,
    0x00,0xea,0x00,0x00,0xc0,
    0x00,0x3f,0x01,0x70,0xc0,
    0x00,0x00,0xff,0xcc,0x30 
  },

  {
    0x00,0x03,0xff,0xfc,0x00,
    0x00,0x3e,0xaa,0xab,0xc0,
    0x03,0xea,0xaa,0xaa,0xb0,
    0x0f,0xaa,0xaa,0xaa,0xac,
    0x0f,0xf6,0xaa,0xab,0xff,
    0x03,0xcd,0xaf,0xaf,0xff,
    0x00,0x03,0x75,0xff,0xfc,
    0x00,0x00,0xd5,0x57,0x3c,
    0x00,0x00,0xd5,0x57,0x3c,
    0x00,0x03,0xe5,0x57,0xfc,
    0x00,0x3e,0xa9,0x63,0xf0,
    0x03,0xea,0xa6,0x80,0xc0,
    0x0e,0xaa,0x98,0x00,0xc0,
    0x3a,0xaa,0x60,0x02,0xc0,
    0x36,0xa9,0x80,0x02,0xc0,
    0x39,0xa6,0x00,0x0a,0xc0,
    0x0e,0x56,0x40,0x0a,0xc0,
    0x03,0xab,0x50,0x03,0x00,
    0x00,0xfc,0xc0,0x03,0x00,
    0x00,0x00,0x3a,0x83,0x00 
  },

  {
    0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x0f,0xfc,0x00,
    0x00,0xf0,0xfa,0xab,0xc0,
    0x03,0xff,0xaa,0xaa,0xb0,
    0x03,0xea,0xaa,0xaa,0xac,
    0x00,0xd6,0xaa,0xab,0xfc,
    0x00,0x3d,0x6a,0xbf,0xff,
    0x00,0x0d,0x5d,0x5f,0xff,
    0x00,0x03,0xd7,0xfc,0xfc,
    0x00,0x00,0x35,0x5c,0xfc,
    0x00,0x00,0xf5,0x5f,0xfc,
    0x00,0x03,0xa9,0x4f,0xf0,
    0x00,0x3e,0xa9,0x80,0x70,
    0x00,0xea,0xa6,0x00,0x70,
    0x03,0xaa,0xa6,0x00,0x70,
    0x0e,0xaa,0x58,0x02,0xc0,
    0x0e,0x55,0xa0,0x0a,0xc0,
    0x39,0xaa,0x00,0x03,0x00,
    0x0e,0xb5,0x50,0x03,0x00,
    0x03,0xcd,0x4c,0x0c,0x00 
  }
};