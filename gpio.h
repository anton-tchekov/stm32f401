struct rcc
{
	volatile unsigned int cr;       /* 0 - control reg */
	volatile unsigned int pll;      /* 4 - pll config */
	volatile unsigned int conf;     /* 8 - clock config */
	volatile unsigned int cir;      /* c - clock interrupt */
	volatile unsigned int ahb1_r;   /* 10 - AHB1 peripheral reset */
	volatile unsigned int ahb2_r;   /* 14 - AHB2 peripheral reset */
	int __pad1[2];
	volatile unsigned int apb1_r;   /* 20 - APB1 peripheral reset */
	volatile unsigned int apb2_r;   /* 24 - APB2 peripheral reset */
	int __pad2[2];
	volatile unsigned int ahb1_e;   /* 30 - AHB1 peripheral enable */
	volatile unsigned int ahb2_e;   /* 34 - AHB2 peripheral enable */
	int __pad3[2];
	volatile unsigned int apb1_e;   /* 40 - APB1 peripheral enable */
	volatile unsigned int apb2_e;   /* 44 - APB2 peripheral enable */
	int __pad4[2];
	volatile unsigned int ahb1_elp; /* 50 - AHB1 peripheral enable in low power */
	volatile unsigned int ahb2_elp; /* 54 - AHB2 peripheral enable in low power */
	int __pad5[2];
	volatile unsigned int apb1_elp; /* 60 - APB1 peripheral enable in low power */
	volatile unsigned int apb2_elp; /* 64 - APB2 peripheral enable in low power */
	int __pad6[2];
	volatile unsigned int bdcr;     /* 70 */
	volatile unsigned int csr;      /* 74 */
	int __pad7[2];
	volatile unsigned int sscgr;    /* 80 */
	volatile unsigned int plli2s;   /* 84 */
	int __pad8;
	volatile unsigned int dccr;     /* 8c */
};

#define GPIOA_ENABLE   0x01
#define GPIOB_ENABLE   0x02
#define GPIOC_ENABLE   0x04
#define GPIOD_ENABLE   0x08
#define GPIOE_ENABLE   0x10
#define GPIOH_ENABLE   0x80

struct gpio
{
	volatile unsigned int mode;   /* 0x00 */
	volatile unsigned int otype;  /* 0x04 */
	volatile unsigned int ospeed; /* 0x08 */
	volatile unsigned int pupd;   /* 0x0c */
	volatile unsigned int idata;  /* 0x10 */
	volatile unsigned int odata;  /* 0x14 */
	volatile unsigned int bsrr;   /* 0x18 */
	volatile unsigned int lock;   /* 0x1c */
	volatile unsigned int afl;    /* 0x20 */
	volatile unsigned int afh;    /* 0x24 */
};

#define RCC            ((struct rcc *)0x40023800)
#define GPIOA          ((struct gpio *)0x40020000)
#define GPIOB          ((struct gpio *)0x40020400)
#define GPIOC          ((struct gpio *)0x40020800)
