%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterl�sung - Aufgabe 12
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule f�r Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Eingabe der Widerst�nde (in Ohm) und Spannungen (in Volt)
R1 = 100;
R2 = 200;
R3 = 300;
R4 = 1000;
U01 = 10;
U02 = 20;

% a) Berechnung mit dem �berlagerungssatz

% Spg.-Quelle 01 aktiv, Spg.-Quelle 02 kurzgeschlossen
Rges1 = R2 + p(R1, R3+R4)       % Gesamtwiderstand f�r Quelle 1
I21 = -U01/Rges1                % durch U01 bewirkter Strom I2
I11 = -I21 * (R3+R4)/(R1+R3+R4) % durch U01 bewirkter Strom I1
I31 = -I21 * R1/(R1+R3+R4)      % durch U01 bewirkter Strom I3

% Spg.-Quelle 02 aktiv, Spg.-Quelle 01 kurzgeschlossen
Rges2 = R3 + R4 + p(R1, R2)     % Gesamtwiderstand f�r Quelle 2
I32 = -U02/Rges2                % durch U02 bewirkter Strom I3
I12 = -I32 * R2/(R1+R2)         % durch U02 bewirkter Strom I1
I22 = -I32 * R1/(R1+R2)         % durch U02 bewirkter Strom I2

% Gesamtstr�me durch �berlagerung der Teilstr�me
I1 = I11 + I12
I2 = I21 + I22
I3 = I31 + I32

% b) Berechnung durch systematische Anwendung der Kirhoff'schen Gesetze

% Aufstellung der Widerstandsmatrix und des Spannungsvektore
R_ = [  1  1     1
       R1 -R2    0
        0  R2 -(R3+R4) ]

U_ = [  0; 
       U01; 
      U02-U01 ]

% L�sung des Gleichungssystems
I = R_\U_     % alternativ: I=inv(R_)*U_
