%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterlösung - Aufgabe 13
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule für Technik Berlin
%--------------------------------------------------------------

clear
close all
home

% Eingabe der Parameter %
R1 = 50;    % in Ohm
R2 = 100;   % in Ohm
R3 = 150;   % in Ohm
R4 = 200;   % in Ohm
R5 = 250;   % in Ohm
U01 = 5;    % in V
U03 = 10;   % in V
I0 = 2e-3;  % in A

U0 = I0*R2; % Umwandlung der Stromquelle in eine Spannungsquelle

% Aufbau der Widerstandsmatrix
R=[ -1   -1    -1   1   0
     1    1     0   0  -1
     0   R2   -R3   0   R5
     0    0    R3   R4  0
     R1   0    0    R4  R5 ]

% Aufbau des Spannungsvektors
U0=[ 0; 0; U02-U03; U03; U01]

% Lösung des Gleichungssystems
I=inv(R)*U0
