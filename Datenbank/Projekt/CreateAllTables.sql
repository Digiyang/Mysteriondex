create table BEHANDLUNG(
	NAME_DER_BEHANDLUNG varchar(40),
	KOSTEN number,

	constraint NAME_DER_BEHANDLUNG_PK 
	primary key(NAME_DER_BEHANDLUNG)
);


create table LOKATION(
	LOKATIONSNR number not null,
	STADT  varchar(60),
	REGION  varchar(30),

	constraint LOKATIONSNR_PK 
	primary key(LOKATIONSNR)
);


Create table PATIENT(
	PATIENTNR number not null,
	GESCHLECHT  varchar(10),
	LOKATION number(3),
	UBERLEBUNGSCHANCEN number(3),
	BEHANDLUNG varchar(30),

	constraint PATIENTNR_PK 
	primary key(PATIENTNR),
	constraint PATIENT_LOKATION_FK
	foreign key (LOKATION)
	references LOKATION(LOKATIONSNR),
	constraint BEHANDLUNG_FK
	foreign key (BEHANDLUNG)
	references BEHANDLUNG(NAME_DER_BEHANDLUNG)
);

create table SELBSTHILFEGRUPPE(
	GRUPPENNR number not null,
	LOKATION number(3),

	constraint GRUPPENNR_PK 
	primary key(GRUPPENNR),
	constraint SHG_LOKATION_FK
	foreign key (LOKATION)
	references LOKATION(LOKATIONSNR)
);

create table ART_DES_KREBS(
	KREBSNAME varchar(30) not null,
	STERBLICHKEIT number(3),

	constraint KREBSNAME_PK 
	primary key(KREBSNAME)
);

create table NACHFOLGEN(
	ART_DER_NACHFOLGEN varchar(30) not null,

	constraint ART_DER_NACHFOLGEN_PK 
	primary key(ART_DER_NACHFOLGEN)
);

create table hat_Krebs(
	KREBSNAME varchar(30) not null,
	PATIENTNR number not null,

	constraint hk_KREBSNAME_FK
	foreign key (KREBSNAME)
	references ART_DES_KREBS (KREBSNAME),
	
	constraint hk_PATIENTNR_FK
	foreign key (PATIENTNR)
	references PATIENT (PATIENTNR)
);

create table ergibt_Nachfolgen(
	NAME_DER_BEHANDLUNG varchar(40) not null,
	PATIENTNR number not null,

	constraint eN_NAME_DER_BEHANDLUNG_FK
	foreign key (NAME_DER_BEHANDLUNG)
	references BEHANDLUNG (NAME_DER_BEHANDLUNG),
	
	constraint eN_PATIENTNR_FK
	foreign key (PATIENTNR)
	references PATIENT (PATIENTNR)
);

create table wird_behandelt(
	KREBSNAME varchar(30) not null,
	NAME_DER_BEHANDLUNG varchar(40) not null,

	constraint wb_KREBSNAME_FK
	foreign key (KREBSNAME)
	references ART_DES_KREBS (KREBSNAME),
	
	constraint wb_NAME_DER_BEHANDLUNG_FK
	foreign key (NAME_DER_BEHANDLUNG)
	references BEHANDLUNG (NAME_DER_BEHANDLUNG)
);

create table Patient_ist_in(
	PATIENTNR number not null,
	GRUPPENNR number not null,
	
	constraint Pii_PATIENTNR_FK
	foreign key (PATIENTNR)
	references PATIENT (PATIENTNR),

	constraint Pii_GRUPPENNR_FK
	foreign key (GRUPPENNR)
	references SELBSTHILFEGRUPPE (GRUPPENNR)
;


create table bekommt_Behandlung(
	PATIENTNR number not null,
	NAME_DER_BEHANDLUNG varchar(40) not null,

	constraint bB_PATIENTNR_FK
	foreign key (PATIENTNR)
	references PATIENT (PATIENTNR),

	constraint bB_NAME_DER_BEHANDLUNG_FK
	foreign key (NAME_DER_BEHANDLUNG)
	references BEHANDLUNG (NAME_DER_BEHANDLUNG)
);

