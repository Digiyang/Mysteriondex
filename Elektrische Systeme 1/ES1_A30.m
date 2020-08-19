%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 30
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

U0 = 400;          % Betrag der Leiterspannungen in V
om = 2*pi*50;      % Kreisfrequenz in 1/s
R = 8;             % Widerstand in Ohm
L = 0.3;           % Induktivität in H
Z = R+j*om*L;      % Scheinwiderstand pro Strang

% Festlegung der Leiterspannungen
U_12 = U0*exp(j*30*pi/180);
U_23 = U0*exp(-j*90*pi/180);
U_31 = U0*exp(j*150*pi/180);

% Berechnung der Strangströme
I_12 = U_12/Z
I_23 = U_23/Z
I_31 = U_31/Z

% Berechnung der Leiterströme
I_1 = I_12 - I_31
I_2 = I_23 - I_12
I_3 = I_31 - I_23

% Komplexe Scheinleistung
S_12 = U_12*conj(I_12)
S_23 = U_23*conj(I_23)
S_31 = U_31*conj(I_31)

Sges = 3*S_12 % Identische Scheinleistung pro Strang (wegen Symmetrie)

% Berechnung der Kompensation:
% Wirk- und Blindleistung eines Stranges
P_Strang = real(S_12)
Q_Strang = imag(S_12)
% Geforderter Phasenwinkel
phi_komp = acos(0.95)
% Geforderte Blindleistung pro Strang
Q_komp = P_Strang * tan(phi_komp)
% Daraus folgende zusätzliche Blindleistung pro Strang
Q_C = Q_komp - Q_Strang
% Erforderlicher Kondensator in Dreieckschaltung
C_Dreieck = -Q_C/(om*U0^2)
% Erforderlicher Kondensator in Sternschaltung
C_Stern = 3*C_Dreieck
