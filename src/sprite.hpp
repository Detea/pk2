/*
*	Pekka Kana 2
*	by Janne Kivilahti from Piste Gamez (2003)
*
*	Community Edition
*	by Deta (2019)
*/

#ifndef PK2SPRITE
#define PK2SPRITE

#include "types.hpp"
#include <string>
#include <vector>

#define PK2SPRITE_VIIMEISIN_VERSIO "1.3"

//#define MAX_SPRITEJA       800
#define MAX_PROTOTYYPPEJA  100
#define MAX_SPRITES 20000

#define SPRITE_MAX_FRAMEJA        50
#define SPRITE_MAX_ANIMAATIOITA   20
#define SPRITE_MAX_AI             10
#define ANIMAATIO_MAX_SEKVENSSEJA 10
#define MAX_AANIA                  7
#define	VAHINKO_AIKA              50 //Damage time?

//Animation
enum Animation {
	STILL,
	WALKING,
	JUMP_UP,
	JUMP_DOWN,
	DUCK,
	DAMAGE,
	KNOCK_OUT,
	ATTACK1,
	ATTACK2,
};

enum { //Sound
    AANI_VAHINKO,
    AANI_TUHOUTUMINEN,
    AANI_HYOKKAYS1,
    AANI_HYOKKAYS2,
    AANI_RANDOM,
    AANI_ERIKOIS1,
    AANI_ERIKOIS2
};
enum { //AI
    AI_EI,
    AI_KANA,
    AI_MUNA,
    AI_PIKKUKANA,
    AI_BONUS,
    AI_HYPPIJA,
    AI_PERUS,
    AI_KAANTYY_ESTEESTA_HORI,
    AI_VAROO_KUOPPAA,
    AI_RANDOM_SUUNNANVAIHTO_HORI,
    AI_RANDOM_HYPPY,
    AI_SEURAA_PELAAJAA,
    AI_RANDOM_ALOITUSSUUNTA_HORI,
    AI_SEURAA_PELAAJAA_JOS_NAKEE,
    AI_MUUTOS_JOS_ENERGIAA_ALLE_2,
    AI_MUUTOS_JOS_ENERGIAA_YLI_1,
    AI_ALOITUSSUUNTA_PELAAJAA_KOHTI,
    AI_AMMUS,
    AI_NONSTOP,
    AI_HYOKKAYS_1_JOS_OSUTTU,
    AI_POMMI,
    AI_HYOKKAYS_1_JOS_PELAAJA_EDESSA,
    AI_HYOKKAYS_1_JOS_PELAAJA_ALAPUOLELLA,
    AI_VAHINGOITTUU_VEDESTA,
    AI_HYOKKAYS_2_JOS_PELAAJA_EDESSA,
    AI_TAPA_KAIKKI,
    AI_KITKA_VAIKUTTAA,
    AI_PIILOUTUU,
    AI_PALAA_ALKUUN_X,
    AI_PALAA_ALKUUN_Y,
    AI_TELEPORTTI,

    AI_HEITTOASE = 35,
    AI_TIPPUU_TARINASTA,
    AI_VAIHDA_KALLOT_JOS_TYRMATTY,
    AI_VAIHDA_KALLOT_JOS_OSUTTU,
    AI_TUHOUTUU_JOS_EMO_TUHOUTUU,

    AI_LIIKKUU_X_COS = 41,
    AI_LIIKKUU_Y_COS,
    AI_LIIKKUU_X_SIN,
    AI_LIIKKUU_Y_SIN,
    AI_LIIKKUU_X_COS_NOPEA,
    AI_LIIKKUU_Y_SIN_NOPEA,
    AI_LIIKKUU_X_COS_HIDAS,
    AI_LIIKKUU_Y_SIN_HIDAS,
    AI_LIIKKUU_Y_SIN_VAPAA,

    AI_RANDOM_KAANTYMINEN,
    AI_HYPPY_JOS_PELAAJA_YLAPUOLELLA,
    AI_MUUTOS_AJASTIN,

    AI_TIPPUU_JOS_KYTKIN1_PAINETTU,
    AI_TIPPUU_JOS_KYTKIN2_PAINETTU,
    AI_TIPPUU_JOS_KYTKIN3_PAINETTU,

    AI_LIIKKUU_ALAS_JOS_KYTKIN1_PAINETTU,
    AI_LIIKKUU_YLOS_JOS_KYTKIN1_PAINETTU,
    AI_LIIKKUU_VASEMMALLE_JOS_KYTKIN1_PAINETTU,
    AI_LIIKKUU_OIKEALLE_JOS_KYTKIN1_PAINETTU,
    AI_LIIKKUU_ALAS_JOS_KYTKIN2_PAINETTU,
    AI_LIIKKUU_YLOS_JOS_KYTKIN2_PAINETTU,
    AI_LIIKKUU_VASEMMALLE_JOS_KYTKIN2_PAINETTU,
    AI_LIIKKUU_OIKEALLE_JOS_KYTKIN2_PAINETTU,
    AI_LIIKKUU_ALAS_JOS_KYTKIN3_PAINETTU,
    AI_LIIKKUU_YLOS_JOS_KYTKIN3_PAINETTU,
    AI_LIIKKUU_VASEMMALLE_JOS_KYTKIN3_PAINETTU,
    AI_LIIKKUU_OIKEALLE_JOS_KYTKIN3_PAINETTU,

    AI_KAANTYY_ESTEESTA_VERT = 70,
    AI_RANDOM_ALOITUSSUUNTA_VERT,
    AI_ALOITUSSUUNTA_PELAAJAA_KOHTI_VERT,
    AI_KIIPEILIJA,
    AI_KIIPEILIJA2,
    AI_PAKENEE_PELAAJAA_JOS_NAKEE,
    AI_UUSI_JOS_TUHOUTUU,

    AI_NUOLI_VASEMMALLE,
    AI_NUOLI_OIKEALLE,
    AI_NUOLI_YLOS,
    AI_NUOLI_ALAS,
    AI_NUOLET_VAIKUTTAVAT,

    AI_TAUSTA_KUU = 101,
    AI_TAUSTA_LIIKKUU_VASEMMALLE,
    AI_TAUSTA_LIIKKUU_OIKEALLE,

    AI_BONUS_AIKA = 120,
    AI_BONUS_NAKYMATTOMYYS,
    AI_BONUS_SUPERHYPPY,
    AI_BONUS_SUPERTULITUS,
    AI_BONUS_SUPERVAUHTI,

    AI_MUUTOS_JOS_OSUTTU = 129,
    AI_SEURAA_PELAAJAA_VERT_HORI,
    AI_SEURAA_PELAAJAA_JOS_NAKEE_VERT_HORI,
    AI_RANDOM_LIIKAHDUS_VERT_HORI,
    AI_SAMMAKKO1,
    AI_SAMMAKKO2,
    AI_SAMMAKKO3,
    AI_HYOKKAYS_2_JOS_OSUTTU,
    AI_HYOKKAYS_1_NONSTOP,
    AI_HYOKKAYS_2_NONSTOP,
    AI_KAANTYY_JOS_OSUTTU,
    AI_EVIL_ONE,

    AI_INFO1 = 201,
    AI_INFO2,
    AI_INFO3,
    AI_INFO4,
    AI_INFO5,
    AI_INFO6,
    AI_INFO7,
    AI_INFO8,
    AI_INFO9,
    AI_INFO10,
    AI_INFO11,
    AI_INFO12,
    AI_INFO13,
    AI_INFO14,
    AI_INFO15,
    AI_INFO16,
    AI_INFO17,
    AI_INFO18,
    AI_INFO19
};
enum { //Damage
    VAHINKO_EI,
    VAHINKO_ISKU,
    VAHINKO_PUDOTUS,
    VAHINKO_MELU,
    VAHINKO_TULI,
    VAHINKO_VESI,
    VAHINKO_LUMI,
    VAHINKO_BONUS,
    VAHINKO_SAHKO,
    VAHINKO_ITSARI,
    VAHINKO_PURISTUS,
    VAHINKO_HAJU,
    VAHINKO_KAIKKI,
    VAHINKO_PISTO
};
enum { //Prototype
    PROTOTYPE_KANA,
    PROTOTYPE_MUNA,
    PROTOTYPE_PIKKUKANA,
    PROTOTYPE_OMENA,
    PROTOTYPE_HYPPIJA
};

//Type
enum {
    type_EI_MIKAAN,
    type_PELIHAHMO,
    type_BONUS,
    type_AMMUS,
    type_TELEPORTTI,
    type_TAUSTA,

	// 1.4
	TYPE_COLLECTABLE,
	TYPE_CHECKPOINT,
	TYPE_EXIT
};

enum { //Color
    VARI_HARMAA   = 0,
    VARI_SININEN  = 32,
    VARI_PUNAINEN = 64,
    VARI_VIHREA   = 96,
    VARI_ORANSSI  = 128,
    VARI_VIOLETTI = 160,
    VARI_TURKOOSI = 192,
    VARI_NORMAALI = 255
};
enum { //Destruction
    TUHOUTUMINEN_EI_TUHOUDU,
    TUHOUTUMINEN_HOYHENET,
    TUHOUTUMINEN_TAHDET_HARMAA,
    TUHOUTUMINEN_TAHDET_SININEN,
    TUHOUTUMINEN_TAHDET_PUNAINEN,
    TUHOUTUMINEN_TAHDET_VIHREA,
    TUHOUTUMINEN_TAHDET_ORANSSI,
    TUHOUTUMINEN_TAHDET_VIOLETTI,
    TUHOUTUMINEN_TAHDET_TURKOOSI,
    TUHOUTUMINEN_RAJAHDYS_HARMAA,
    TUHOUTUMINEN_RAJAHDYS_SININEN,
    TUHOUTUMINEN_RAJAHDYS_PUNAINEN,
    TUHOUTUMINEN_RAJAHDYS_VIHREA,
    TUHOUTUMINEN_RAJAHDYS_ORANSSI,
    TUHOUTUMINEN_RAJAHDYS_VIOLETTI,
    TUHOUTUMINEN_RAJAHDYS_TURKOOSI,
    TUHOUTUMINEN_SAVU_HARMAA,
    TUHOUTUMINEN_SAVU_SININEN,
    TUHOUTUMINEN_SAVU_PUNAINEN,
    TUHOUTUMINEN_SAVU_VIHREA,
    TUHOUTUMINEN_SAVU_ORANSSI,
    TUHOUTUMINEN_SAVU_VIOLETTI,
    TUHOUTUMINEN_SAVU_TURKOOSI,
    TUHOUTUMINEN_SAVUPILVET,
    TUHOUTUMINEN_ANIMAATIO = 100
};
enum { //Bonus Item
    BONUSESINE_EI_MITAAN,
    BONUSESINE_AVAIN,
    BONUSESINE_PISTE
};

struct PK2SPRITE_ANIMAATIO{
    uint8_t		sekvenssi[ANIMAATIO_MAX_SEKVENSSEJA];	// sequence
    BYTE		frameja;								// frames
    bool		looppi;									// loop
};

// Needed, because PK2SPRITE_ANIMAATIO is read from the file. This struct contains "last_frame", which isn't saved in the file
// TODO Store last_frame in sprite file format 1.4
struct AnimationData {
	uint8_t frames[ANIMAATIO_MAX_SEKVENSSEJA];
	uint8_t frame_amount;
	
	uint8_t last_frame;

	bool loop;
};

//.spr file structures
struct PK2Sprite_Prototype10{

    DWORD		type;											// spriten type
    // image_filen tiedot
    char		image_file[13];								// .BMP jossa ovat spriten grafiikat
    // Spriteen liittyv�t ��nitehosteet
    char		aanitiedostot[7][13];							// ��nitehostetiedostot
    DWORD		aanet[7];										// ��nitehosteet (indeksit buffereihin)
    // Spriten kuva- ja animaatio-ominaisuudet
    BYTE		frameja;										// framejen m��r�
    PK2SPRITE_ANIMAATIO animaatiot[20];							// animaatio sekvenssit
    BYTE		animaatioita;									// animaatioiden m��r�
    BYTE		frame_rate;										// yhden framen kesto
    DWORD		kuva_x;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_y;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_frame_leveys;								// yhden framen leveys
    DWORD		kuva_frame_korkeus;								// yhden framen korkeus
    DWORD		kuva_frame_vali;								// kahden framen vali
    // Spriten ominaisuudet
    char		nimi[30];										// spriten nimi (n�kyy editorissa)
    DWORD		leveys;											// spriten leveys
    DWORD		korkeus;										// spriten korkeus
    double		paino;											// sprite paino (vaikuttaa hyppyyn ja kytkimiin)
    bool		vihollinen;										// onko sprite vihollinen
    DWORD		energia;										// monta iskua kest��
    DWORD		vahinko;										// paljon vahinkoa tekee jos osuu
    DWORD		pisteet;										// paljonko siit� saa pisteit�
    DWORD		AI[5];											// mit� teko�lyj� k�ytet��n
    DWORD		suojaus;										// miten suojattu iskuilta
    BYTE		max_hyppy;										// hypyn maksimikesto
    BYTE		max_nopeus;										// maksimi nopeus
    DWORD		latausaika;										// ampumisen j�lkeinen odotus
    BYTE		vari;											// tehd��nk� spritest� jonkin tietyn v�rinen
    bool		este;											// k�ytt�ytyyk� sprite kuin sein�
    DWORD		tuhoutuminen;									// miten sprite tuhoutuu
    // Yhteys toisiin spriteihin
    char		transformation_sprite[13];								// Toinen sprite joksi t�m� sprite voi muuttua
    char		bonus_sprite[13];								// Spriten bonuksena j�tt�m� k�ytt�m� sprite
    char		ammus1_sprite[13];								// Spriten ammuksena 1 k�ytt�m� sprite
    char		ammus2_sprite[13];								// Spriten ammuksena 2 k�ytt�m� sprite
    bool		avain;											// Voiko sprite avata lukkoja
};
struct PK2Sprite_Prototype11{

    DWORD		type;											// spriten type
    // image_filen tiedot
    char		image_file[13];								// .BMP jossa ovat spriten grafiikat
    // Spriteen liittyv�t ��nitehosteet
    char		aanitiedostot[7][13];							// ��nitehostetiedostot
    DWORD		aanet[7];										// ��nitehosteet (indeksit buffereihin)
    // Spriten kuva- ja animaatio-ominaisuudet
    BYTE		frameja;										// framejen m��r�
    PK2SPRITE_ANIMAATIO animaatiot[20];							// animaatio sekvenssit
    BYTE		animaatioita;									// animaatioiden m��r�
    BYTE		frame_rate;										// yhden framen kesto
    DWORD		kuva_x;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_y;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_frame_leveys;								// yhden framen leveys
    DWORD		kuva_frame_korkeus;								// yhden framen korkeus
    DWORD		kuva_frame_vali;								// kahden framen vali
    // Spriten ominaisuudet
    char		nimi[30];										// spriten nimi (n�kyy editorissa)
    DWORD		leveys;											// spriten leveys
    DWORD		korkeus;										// spriten korkeus
    double		paino;											// sprite paino (vaikuttaa hyppyyn ja kytkimiin)
    bool		vihollinen;										// onko sprite vihollinen
    DWORD		energia;										// monta iskua kest��
    DWORD		vahinko;										// paljon vahinkoa tekee jos osuu
    BYTE        vahinko_type;									// Mink� typest� vahinkoa tekee (1.1)
    BYTE		suojaus;										// Mink� typeselt� vahingolta on suojattu
    DWORD		pisteet;										// paljonko siit� saa pisteit�
    DWORD		AI[5];											// mit� teko�lyj� k�ytet��n
    BYTE		max_hyppy;										// hypyn maksimikesto
    BYTE		max_nopeus;										// maksimi nopeus
    DWORD		latausaika;										// ampumisen j�lkeinen odotus
    BYTE		vari;											// tehd��nk� spritest� jonkin tietyn v�rinen
    bool		este;											// k�ytt�ytyyk� sprite kuin sein�
    DWORD		tuhoutuminen;									// miten sprite tuhoutuu
    bool		avain;											// Voiko sprite avata lukkoja
    bool		tarisee;										// Tariseek� sprite satunnaisesti
    BYTE        bonusten_lkm;									// Bonusten lukum��r�
    DWORD       hyokkays1_aika;									// Hy�kk�ysanimaation 1 kesto (frameja)
    DWORD       hyokkays2_aika;									// Hy�kk�ysanimaation 2 kesto (frameja)
    DWORD		pallarx_kerroin;								// Vain type_TAUSTA. Suhde taustakuvaan.
    // Yhteys toisiin spriteihin
    char		transformation_sprite[13];								// Toinen sprite joksi t�m� sprite voi muuttua
    char		bonus_sprite[13];								// Spriten bonuksena j�tt�m� k�ytt�m� sprite
    char		ammus1_sprite[13];								// Spriten ammuksena 1 k�ytt�m� sprite
    char		ammus2_sprite[13];								// Spriten ammuksena 2 k�ytt�m� sprite

};
struct PK2Sprite_Prototype12{

    DWORD		type;											// spriten type
    // image_filen tiedot
    char		image_file[13];								// .BMP jossa ovat spriten grafiikat
    // Spriteen liittyv�t ��nitehosteet
    char		aanitiedostot[7][13];							// ��nitehostetiedostot
    DWORD		aanet[7];										// ��nitehosteet (indeksit buffereihin)
    // Spriten kuva- ja animaatio-ominaisuudet
    BYTE		frameja;										// framejen m��r�
    PK2SPRITE_ANIMAATIO animaatiot[20];							// animaatio sekvenssit
    BYTE		animaatioita;									// animaatioiden m��r�
    BYTE		frame_rate;										// yhden framen kesto
    DWORD		kuva_x;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_y;											// miss� kohtaa kuvaa sprite on
    DWORD		kuva_frame_leveys;								// yhden framen leveys
    DWORD		kuva_frame_korkeus;								// yhden framen korkeus
    DWORD		kuva_frame_vali;								// kahden framen vali
    // Spriten ominaisuudet
    char		nimi[30];										// spriten nimi (n�kyy editorissa)
    DWORD		leveys;											// spriten leveys
    DWORD		korkeus;										// spriten korkeus
    double		paino;											// sprite paino (vaikuttaa hyppyyn ja kytkimiin)
    bool		vihollinen;										// onko sprite vihollinen
    DWORD		energia;										// monta iskua kest��
    DWORD		vahinko;										// paljon vahinkoa tekee jos osuu
    BYTE        vahinko_type;									// Mink� typest� vahinkoa tekee (1.1)
    BYTE		suojaus;										// Mink� typeselt� vahingolta on suojattu
    DWORD		pisteet;										// paljonko siit� saa pisteit�
    DWORD		AI[5];											// mit� teko�lyj� k�ytet��n
    BYTE		max_hyppy;										// hypyn maksimikesto
    BYTE		max_nopeus;										// maksimi nopeus
    DWORD		latausaika;										// ampumisen j�lkeinen odotus
    BYTE		vari;											// tehd��nk� spritest� jonkin tietyn v�rinen
    bool		este;											// k�ytt�ytyyk� sprite kuin sein�
    DWORD		tuhoutuminen;									// miten sprite tuhoutuu
    bool		avain;											// Voiko sprite avata lukkoja
    bool		tarisee;										// Tariseek� sprite satunnaisesti
    BYTE        bonusten_lkm;									// Bonusten lukum��r�
    DWORD       hyokkays1_aika;									// Hy�kk�ysanimaation 1 kesto (frameja)
    DWORD       hyokkays2_aika;									// Hy�kk�ysanimaation 2 kesto (frameja)
    DWORD		pallarx_kerroin;								// Vain type_TAUSTA. Suhde taustakuvaan.
    // Yhteys toisiin spriteihin
    char		transformation_sprite[13];								// Toinen sprite joksi t�m� sprite voi muuttua
    char		bonus_sprite[13];								// Spriten bonuksena j�tt�m� k�ytt�m� sprite
    char		ammus1_sprite[13];								// Spriten ammuksena 1 k�ytt�m� sprite
    char		ammus2_sprite[13];								// Spriten ammuksena 2 k�ytt�m� sprite

    bool		tiletarkistus;									// t�rm�ileek� tileihin
    DWORD		aani_frq;										// ��nien perussoittotaajuus (esim. 22050)
    bool		random_frq;										// satunnaisuutta taajuuteen?

    // Jos sprite on este
    bool		este_ylos;
    bool		este_alas;
    bool		este_oikealle;
    bool		este_vasemmalle;

};

struct PK2Sprite_Prototype13 {

    DWORD		type;											// sprite type
    char		image_file[100];								// bmp path
    char		aanitiedostot[7][100];							// sound path (max 7)
    DWORD		aanet[7];										// sound types


    BYTE		frameja;										// number of frames
    PK2SPRITE_ANIMAATIO animaatiot[20];							// animation sequences
    BYTE		animaatioita;									// number of animations
    BYTE		frame_rate;										// frame rate
    DWORD		kuva_x;											// x position of first frame
    DWORD		kuva_y;											// y position of first frame
    DWORD		kuva_frame_leveys;								// frame width
    DWORD		kuva_frame_korkeus;								// frame height
    DWORD		kuva_frame_vali;								// space between frames


    char		nimi[30];										// name
    DWORD		leveys;											// width
    DWORD		korkeus;										// height
    double		paino;											// weight (for jump and switches)
    bool		vihollinen;										// if sprite is a enemy
    DWORD		energia;										//?sprite energy
    DWORD		vahinko;										//?damage if hitted
    BYTE        vahinko_type;									//?damage type
    BYTE		suojaus;										//?protection type
    DWORD		pisteet;										// how much score
    DWORD		AI[10];											// AI type (max 10)
    BYTE		max_hyppy;										// max jump time
    double		max_nopeus;										// max speed
    DWORD		latausaika;										//?wait post shoot
    BYTE		vari;											// color
    bool		este;											// is a wall
    DWORD		tuhoutuminen;									// how sprite is destroyed
    bool		avain;											// can sprite open locks
    bool		tarisee;										//?sprite randomly
    BYTE        bonusten_lkm;									// number of bonuses
    DWORD       hyokkays1_aika;									// attack 1 duration (frames)
    DWORD       hyokkays2_aika;									// attack 2 duration (frames)
    DWORD		pallarx_kerroin;								// parallax type (just to type_TAUSTA)


    char		transformation_sprite[100];								// another sprite that this sprite may change
    char bonus_sprite[100];								// bonus that this sprite gives
    char ammus1_sprite[100];								// ammo 1 sprite
    char ammus2_sprite[100];								// ammo 2 sprite


    bool		tiletarkistus;									//?make sounds?
    DWORD		aani_frq;										// sound frequency (def. 22050)
    bool		random_frq;										// use random frequency?


    bool		este_ylos;                                      // if is wall at up
    bool		este_alas;                                      // if is wall at down
    bool		este_oikealle;                                  // if is wall at right
    bool		este_vasemmalle;                                // if is wall at left


    BYTE		lapinakyvyys;									// transparency
    bool		hehkuu;											// is transparent?
    DWORD		tulitauko;										//*ammuspriten ampujalle aiheuttama latausaika
    bool		liitokyky;										//*voiko tippua hiljaa alas?
    bool		boss;											// if it is a boss
    bool		bonus_aina;										// allways gives bonus
    bool		osaa_uida;										// be alive in water
};

struct PK2Sprite_Prototype14 {
	BYTE type;

	std::string image_file = "";
	std::string lua_script;

	char sound_files[5][100];

	BYTE frames;
	PK2SPRITE_ANIMAATIO animation_sequence[20];
	
	BYTE animations;
	BYTE frame_rate;

	int clip_x;
	int clip_y;
	int clip_width;
	int clip_height;
	
	std::string	name;
	int hitbox_x;
	int hitbox_y;
	int hitbox_width;
	int hitbox_height;
	
	double weight;

	bool is_enemy;

	int energy;

	// The amount of damage this sprite causes
	int damage;

	// The type of damage this sprite causes
	BYTE damage_type;
	
	// Damage type this sprite isn't hurt by. See Damage list.
	BYTE immunity;

	// If the sprite is a game character, then score is the number of points you get when you knock it out.
	// If sprite is a bonus item sprite, then score is the amount of points you get when you collect the bonus item.
	int score;

	int AI[10];

	BYTE max_jump_time;	

	double max_speed;

	// How many frames to wait, after shooting
	int loading_time;

	// See color list
	BYTE color;

	// Is the sprite a wall?
	bool obstacle;

	// Knock out effect. See Destruction Style list.
	int destruction;

	// can sprite open locks
	bool is_key;

	// sprite shakes randomly
	bool shakes;

	// Amount of bonuses, per sprite
	int bonus_amount[5];

	// How many frames the attack sprite is alive
	int attack1_frames;
	int attack2_frames;

	int parallax_factor;

	std::string	transformation_sprite;

	std::string bonus_sprite[5];				

	std::string	ammo1_sprite;
	std::string	ammo2_sprite;

	std::string message;

	bool tile_check;

	// sound frequency (def. 22050)
	int sound_frq;

	// use random frequency?
	bool random_frq;

	// If sprite acts as a wall up, down...
	bool wall_up;
	bool wall_down;
	bool wall_right;
	bool wall_left;

	//BYTE transparency;									// transparency
	//bool glow;									
	
	int	attack_pause;
	
	bool can_glide;
	bool is_boss;
	bool bonus_always;

	// If true, sprite won't be affected by gravity, when in water
	bool can_swim;

	// Sprite transforms if it's energy is below this value
	int transformation_value;

	int message_duration = 0;
	bool show_message_on_collision = false;
	bool show_message_on_hit = false;

	int attack_priority = 0;
};

//Classes used in game
class PK2Sprite_Prototype {
    public:

    //Version
    char		versio[4];
    //.spr filename
	std::string file = "";

    //Prototype index
    int			indeksi = -1;
    //Sprite type
    int			type = -1;

    //.bmp filename
    std::string	image_file = "";								// .BMP jossa ovat spriten grafiikat

    // Spriteen liittyv�t ��nitehosteet

    char		aanitiedostot[MAX_AANIA][100];					// ��nitehostetiedostot
    int			aanet[MAX_AANIA];								// ��nitehosteet (indeksit buffereihin)

    // Spriten kuva- ja animaatio-ominaisuudet
    int			framet[SPRITE_MAX_FRAMEJA];						// spriten framet (bitm�pit)
    int			framet_peilikuva[SPRITE_MAX_FRAMEJA];			// spriten framet peilikuvina
    BYTE		frameja;										// framejen m��r�
	
	// TODO Remove this and use "animations" instead
    PK2SPRITE_ANIMAATIO animaatiot[SPRITE_MAX_ANIMAATIOITA];	// animaatio sekvenssit

	AnimationData animations[SPRITE_MAX_ANIMAATIOITA];

    BYTE		animaatioita;									// animaatioiden m��r�
    BYTE		frame_rate;										// yhden framen kesto
    int			kuva_x = 0;											// miss� kohtaa kuvaa sprite on
    int			kuva_y = 0;											// miss� kohtaa kuvaa sprite on
    int			kuva_frame_leveys = 1;								// yhden framen leveys
    int			kuva_frame_korkeus = 1;								// yhden framen korkeus
    int			kuva_frame_vali;								// kahden framen vali

	int originalX, originalY;

	int hitbox_x;
	int hitbox_y;

    // Spriten ominaisuudet
    std::string	nimi;										// spriten nimi (n�kyy editorissa)
    int			leveys;											// spriten leveys
    int			korkeus;										// spriten korkeus
    double		paino;											// sprite paino (vaikuttaa hyppyyn ja kytkimiin)

    bool		vihollinen;										// onko sprite vihollinen
    int			energia;										// monta iskua kest��
    int			vahinko;										// paljon vahinkoa tekee jos osuu
    BYTE       vahinko_type;									// mink� typest� vahinkoa tekee (1.1)
    BYTE		suojaus;										// mink� typeselt� vahingolta on suojattu (1.1)
    int			pisteet;										// paljonko siit� saa pisteit�

    int			AI[SPRITE_MAX_AI];								// mit� teko�lyj� k�ytet��n

    BYTE		max_hyppy;										// hypyn maksimikesto
    double		max_nopeus;										// maksiminopeus
    int			latausaika;										// ampumisen j�lkeinen odotus
    BYTE		vari;											// tehd��nk� spritest� jonkin tietyn v�rinen
    bool		este;											// k�ytt�ytyyk� sprite kuin sein�
    int			tuhoutuminen;									// miten sprite tuhoutuu
    bool		avain;											// Voiko sprite avata lukkoja
    bool		tarisee;										// T�riseek� sprite satunnaisesti
    int			bonus_amount[5];									// Bonusten lukum��r�
    int         hyokkays1_aika;									// Hy�kk�ysanimaation 1 kesto (frameja)
    int         hyokkays2_aika;									// Hy�kk�ysanimaation 2 kesto (frameja)

    int			pallarx_kerroin;								// Vain type_TAUSTA. Suhde taustakuvaan.

    // Yhteys toisiin spriteihin

    std::string transformation_sprite;								// Toinen sprite joksi t�m� sprite voi muuttua
    std::string bonus_sprite[5];								// Spriten bonuksena j�tt�m� k�ytt�m� sprite
    std::string ammus1_sprite;								// Spriten ammuksena 1 k�ytt�m� sprite
    std::string ammus2_sprite;								// Spriten ammuksena 2 k�ytt�m� sprite

	int			muutos = -1;											// Muutosspriten prototyypin indeksi. -1 jos ei ole
    int			bonus[5];											// Bonusspriten prototyypin indeksi. -1 jos ei ole
	int			ammus1 = -1;											// Ammussprite1 prototyypin indeksi. -1 jos ei ole
    int			ammus2 = -1;											// Ammussprite1 prototyypin indeksi. -1 jos ei ole

    // Lis�ykset 1.2 versiossa
    bool		tiletarkistus;									// t�rm�ileek� tileihin
    DWORD		aani_frq;										// ��nien perussoittotaajuus (esim. 22050)
    bool		random_frq;										// satunnaisuutta taajuuteen?

    // Jos sprite on este
    bool		este_ylos;
    bool		este_alas;
    bool		este_oikealle;
    bool		este_vasemmalle;

    // Lis�ykset 1.3 versiossa
    BYTE		lapinakyvyys;									// 0 = ei n�y - 100 = ei l�pin�kyv�
    bool		hehkuu;											// 0 = ei hehku (t�ytyy olla l�pin�kyv�)
    int			tulitauko;										// ammuspriten ampujalle aiheuttama latausaika
    bool		liitokyky;										// voiko tippua hiljaa alas?
    bool		boss;											// onko johtaja
    bool		bonus_aina;										// j�tt�� aina bonuksen tuhoutuessa
    bool		osaa_uida;										// vaikuttaako painovoima vedess�?

	// version 1.4
	std::string lua_script;
	int transformation_value;

	std::string message;
	int message_duration = 0;

	bool show_message_on_collision = false;
	bool show_message_on_hit = false;

	int attack_priority = 0;

    // Muodostimet
    PK2Sprite_Prototype();
    ~PK2Sprite_Prototype();

    // Methods
    void New();
    int  Animaatio_Uusi(int anim_i, BYTE *sekvenssi, bool looppi);
    int  Lataa(char *polku, char *tiedoston_nimi, char* episode = nullptr);
	int Load(std::string filename, std::string episode);
    void Tallenna(char *tiedoston_nimi);
    int  Piirra(int x, int y, int frame);
    bool Onko_AI(int AI);

    void SetProto10(PK2Sprite_Prototype10 &proto);
    void SetProto11(PK2Sprite_Prototype11 &proto);
    void SetProto12(PK2Sprite_Prototype12 &proto);
    void SetProto13(PK2Sprite_Prototype13 &proto);
    void SetProto14(PK2Sprite_Prototype14 &proto);
    PK2Sprite_Prototype13 GetProto13();
};
class PK2Sprite {
    public:

    bool		aktiivinen;			// true / false
    int			pelaaja;			// 0 = ei pelaaja, 1 = pelaaja
    PK2Sprite_Prototype *type;	// osoitin spriten prototypein
    bool		piilota;			// true = ei toiminnassa, false = toiminnassa
    double		alku_x = 0;				// spriten alkuper�inen x sijainti
    double		alku_y = 0;				// spriten alkuper�inen y sijainti
    double		x = 0;					// x-kordinaatti pelikent�ll�
    double		y = 0;					// y-kordinaatti pelikent�ll�

	int originalX;
	int originalY;

    double		a;					// horizontal speed
    double		b;					// vertical speed
    bool		flip_x;				// true = peilikuva sivusuunnassa
    bool		flip_y;				// true = peilikuva pystysuunnassa
    int			hyppy_ajastin;		// hypyn kesto: 0 = ei hypyss�, > 0 = hypyss�, < 0 = tullut alas
    bool		ylos;				// voiko sprite juuri nyt liikkua yl�s
    bool		alas;				// voiko sprite juuri nyt liikkua ....
    bool		oikealle;			// voiko sprite juuri nyt liikkua ....
    bool		vasemmalle;			// voiko sprite juuri nyt liikkua ....
    bool		reuna_vasemmalla;	// onko spriten vasemmalla puolella kuoppa?
    bool		reuna_oikealla;		// onko spriten vasemmalla puolella kuoppa?
    int			energia;			// monta osumaa sprite viel� kest��
    int			emosprite;			// jos spriten on luonut jokin toinen sprite
    double		paino;				// spriten oma yksil�llinen paino
    double		kytkinpaino;		// spriten paino + muiden spritejen panot, joihin kosketaan
    bool		kyykky;				// onko sprite kyykyss�
    int			isku;				// onko sprite saanut vahinkoa
    int			lataus;				// jos on ammuttu, odotetaan
    int			hyokkays1;			// ajastin joka laskee hy�kk�ys 1:n j�lkeen
    int			hyokkays2;			// ajastin joka laskee hy�kk�ys 2:n j�lkeen
    bool		vedessa;			// onko sprite vedess�
    bool		piilossa;			// onko sprite piilossa
    double      alkupaino;			// spriten alkuper�inen paino - sama kuin prototyypin
    int			saatu_vahinko;		// v�hennet��n energiasta jos erisuuri kuin 0
    BYTE       saatu_vahinko_type; // saadun vahingon type (esim. lumi).
    bool		vihollinen;			// prototyypist� saatu tieto, onko vihollinen
    int			ammus1 = -1;				// spriten k�ytt�m�n ammus-prototyypin indeksi
    int			ammus2 = -1;				//

    int			pelaaja_x,			// tieto siit�, miss� pelaaja on n�hty viimeksi
    pelaaja_y;

    int			ajastin;			// ajastin jonka arvo py�rii v�lill� 1 - 32000

    uint8_t		current_animation;
	uint8_t		current_frame;

    BYTE		frame_aika;			// kuinka kauan frame on n�kynyt
    int			transformation_ajastin;		// sprite muuttuu muutosspriteksi kun t�m� nollautuu

	// Used for checkpoint animation
	bool checkpoint_activated = false;
	bool knockout_complete = false;

	int transformation_value = 0;

	std::string message;

	int message_duration = 0;
	bool show_message_on_collision = false;
	bool show_message_on_hit = false;

	int attack_priority = 0;

    PK2Sprite();
    PK2Sprite(PK2Sprite_Prototype *type, int pelaaja, bool piilota, double x, double y);
    ~PK2Sprite();
    int Piirra(int kamera_x, int kamera_y);		// Animoi ja piirt�� spriten
    void Animate(int anim_i, bool loop);	// Vaihtaa spriten animaation
    int Animoi();								// Animoi muttei piirr� sprite�
    bool Onko_AI(int AI);						// Palauttaa true, jos spritell� on ko. AI

    //AI_Functions
    int AI_Kana();
    int AI_Bonus();
    int AI_Muna();
    int AI_Ammus();
    int AI_Hyppija();
    int AI_Sammakko1();
    int AI_Sammakko2();
    int AI_Perus();
    int AI_Kaantyy_Esteesta_Hori();
    int AI_Kaantyy_Esteesta_Vert();
    int AI_Varoo_Kuoppaa();
    int AI_Random_Kaantyminen();
    int AI_Random_Suunnanvaihto_Hori();
    int AI_Random_Hyppy();
    int AI_Random_Liikahdus_Vert_Hori();
    int AI_Seuraa_Pelaajaa(PK2Sprite *pelaaja);
    int AI_Seuraa_Pelaajaa_Jos_Nakee(PK2Sprite *pelaaja);
    int AI_Seuraa_Pelaajaa_Jos_Nakee_Vert_Hori(PK2Sprite *pelaaja);
    int AI_Seuraa_Pelaajaa_Vert_Hori(PK2Sprite *pelaaja);
    int AI_Jahtaa_Pelaajaa(PK2Sprite *pelaaja);
    int AI_Pakenee_Pelaajaa_Jos_Nakee(PK2Sprite *pelaaja);
    int AI_Transformation_Jos_Energiaa_Alle_2(PK2Sprite_Prototype &muutos);
    int AI_Transformation_Jos_Energiaa_Yli_1(PK2Sprite_Prototype &muutos);
    int AI_Transformation_Ajastin(PK2Sprite_Prototype &muutos);
    int AI_Transformation_Jos_Osuttu(PK2Sprite_Prototype &muutos);
    int AI_Hyokkays_1_Jos_Osuttu();
    int AI_Hyokkays_2_Jos_Osuttu();
    int AI_Hyokkays_1_Nonstop();
    int AI_Hyokkays_2_Nonstop();
    int AI_Hyokkays_1_Jos_Pelaaja_Edessa(PK2Sprite *pelaaja);
    int AI_Hyokkays_2_Jos_Pelaaja_Edessa(PK2Sprite *pelaaja);
    int AI_Hyokkays_1_Jos_Pelaaja_Alapuolella(PK2Sprite *pelaaja);
    int AI_NonStop();
    int AI_Hyppy_Jos_Pelaaja_Ylapuolella(PK2Sprite *pelaaja);
    int AI_Pommi();
    int AI_Vahingoittuu_Vedesta();
    int AI_Tapa_Kaikki();
    int AI_Kitka_Vaikuttaa();
    int AI_Piiloutuu();
    int AI_Palaa_Alkuun_X();
    int AI_Palaa_Alkuun_Y();
    int AI_Kaantyy_Jos_Osuttu();
    int AI_Tippuu_Tarinasta(int tarina);
    int AI_Liikkuu_X(double liike);
    int AI_Liikkuu_Y(double liike);
    int AI_Tippuu_Jos_Kytkin_Painettu(int kytkin);
    int AI_Liikkuu_Jos_Kytkin_Painettu(int kytkin, int ak, int bk);
    int AI_Teleportti(int i, std::vector<PK2Sprite> &spritet, int max, PK2Sprite &pelaaja);
    int AI_Kiipeilija();
    int AI_Kiipeilija2();
    bool AI_Info(PK2Sprite &pelaaja);
    int AI_Tuhoutuu_Jos_Emo_Tuhoutuu(std::vector<PK2Sprite> &sprites);

	// TODO change these to void return types
    int Animaatio_Perus();
    int Animaatio_Kana();
    int Animaatio_Bonus();
    int Animaatio_Muna();
    int Animaatio_Ammus();

	void Animate_Checkpoint();
};

#endif
