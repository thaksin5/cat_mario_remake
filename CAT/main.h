#include "DxLib.h"
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

void loadg();

//String 使用 (Using Strings)

//プログラム中 (in program)
//main-10
//タイトル-100 (Title-100)
int main=100,maintm=0;

//ステージ (stage)
int stagecolor=0;
int sta=1,stb=4,stc=0;

//クイック (fast or speed) 
int fast=1;

//トラップ表示 (trap display)
int trap=1;

//中間ゲート (middle gate)
int tyuukan=0;


//スタッフロール (stuffed roll)
int ending=0;


//ステージ読み込みループ(いじらない) (Stage loading loop (no fiddling))
int stagerr,stagepoint;
//オーバーフローさせる (overflow)
int over=0;

//ステージスイッチ stage switch
int stageonoff=0;


//メインプログラム main program
void Mainprogram();
void rpaint();
int maint;


//サブクラス subclass
//(ウエイト系 (我不知道英文怎麽翻譯) 
void wait(int interval);
void wait2(long stime, long etime,int FLAME_TIME);
int rand(int Rand);
void end();

//描画 drawing
int color;
void setfont(int a);
void setcolor(int red, int green, int blue);
void setc0();
void setc1();
void drawpixel(int a,int b);
void drawline(int a,int b,int c,int d);
void drawrect(int a,int b,int c,int d);
void fillrect(int a,int b,int c,int d);
void drawarc(int a,int b,int c,int d);
void fillarc(int a,int b,int c,int d);
int grap[161][8],mgrap[51];
int loadimage(string b);
int loadimage(int a,int x,int y,int r,int z);
int mirror;
void drawimage(int mx,int a,int b);
void drawimage(int mx,int a,int b,int c,int d,int e,int f);
void setre();
void setre2();
void setno();
int oto[151];
void ot(int x);void bgmchange(int x);

//文字 character
void str(string c,int a,int b);


//)

void stagecls();
void stage();
void stagep();





//1-ステージ （1-Stage）
//10-ステージ前 (10-before stage)
//



//ループ (loop)
int t,tt,t1,t2,t3,t4;


//初期化 Initialization
int zxon,zzxon;

//キーコンフィグ (key configuration or key setting)
int key,keytm;

//三角関数 Trigonometric function
double pai=3.1415926535;


//地面 Ground
#define smax 31
int sx,sco;
int sa[smax],sb[smax],sc[smax],sd[smax],stype[smax],sxtype[smax],sr[smax];
int sgtype[smax];



//プレイヤー player
int mainmsgtype;
int ma,mb,mnobia,mnobib,mhp;
int mc,md,macttype,atkon,atktm,mactsok,msstar,nokori=2,mactp,mact;

int mtype,mxtype,mtm,mzz;
int mzimen,mrzimen,mkasok,mmuki,mmukitm,mjumptm,mkeytm,mcleartm;
int mmutekitm,mmutekion;
int mztm,mztype;
int actaon[7];
//メッセージ message
int mmsgtm,mmsgtype;

int mascrollmax=21000;//9000




//ブロック clock
void tyobi(int x,int y,int type);
void brockbreak(int t);
#define tmax 641
int tco;
int ta[tmax],tb[tmax],tc[tmax],td[tmax],thp[tmax],ttype[tmax];
int titem[tmax],txtype[tmax];

//メッセージブロック message block
int tmsgtm,tmsgtype,tmsgx,tmsgy,tmsgnobix,tmsgnobiy,tmsg;
void ttmsg();void txmsg(string x,int a);
void setfont(int x,int y);
 
//効果を持たないグラ graphics that have no effect
void eyobi(int xa,int xb,int xc,int xd,int xe,int xf,int xnobia,int xnobib,int xgtype,int xtm);
#define emax 201
int eco;
int ea[emax],eb[emax],enobia[emax],enobib[emax],ec[emax],ed[emax];
int ee[emax],ef[emax],etm[emax];
int egtype[emax];



//敵キャラ enemy character
void ayobi(int xa,int xb,int xc,int xd,int xnotm,int xtype,int xxtype);
void tekizimen();
#define amax 24
int aco;
int aa[amax],ab[amax],anobia[amax],anobib[amax],ac[amax],ad[amax];
int ae[amax],af[amax],abrocktm[amax];
int aacta[amax],aactb[amax],azimentype[amax],axzimen[amax];
int atype[amax],axtype[amax],amuki[amax],ahp[amax];
int anotm[amax],anx[160],any[160];
int atm[amax],a2tm[amax];
int amsgtm[amax],amsgtype[amax];

//敵出現 Enemy Appearance
#define bmax 81
int bco;
int ba[bmax],bb[bmax],btm[bmax];
int btype[bmax],bxtype[bmax],bz[bmax];


//背景 background
#define nmax 41
int nxxmax,nco;
int na[nmax],nb[nmax],nc[nmax],nd[nmax],ntype[nmax];
int ne[nmax],nf[nmax],ng[nmax],nx[nmax];


//リフト
#define srmax 21
int srco;
int sra[srmax],srb[srmax],src[srmax],srd[srmax],sre[srmax],srf[srmax];
int srtype[srmax],srgtype[srmax],sracttype[srmax],srsp[srmax];
int srmuki[srmax],sron[srmax],sree[srmax];
int srsok[srmax],srmovep[srmax],srmove[srmax];





//スクロール範囲 scroll range
int fx=0,fy=0,fzx,fzy,scrollx,scrolly;
//全体のポイント whole point
int fma=0,fmb=0;
//強制スクロール forced scroll
int kscroll=0;
//画面サイズ(ファミコンサイズ×2)(256-224) => (Screen size (Famicom size x 2) (256-224))
int fxmax=48000,fymax=42000;



//ステージ stage 
byte stagedate[17][2001];

//画面黒 screen black
int blacktm=1,blackx=0;screen black



//自由な値 free value
int xx[91];
double xd[11];
string xs[31];


long stime;
