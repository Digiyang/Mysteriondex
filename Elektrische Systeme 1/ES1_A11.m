%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterl�sung - Aufgabe 11
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule f�r Technik Berlin
%--------------------------------------------------------------

clear
close all
home

R = 1  % Eingabe in Ohm

% L�sung durch rekursiven Aufruf der Funktion p(R1,R2),
% die den Wert der Parallelschaltung von R1 und R2 berechnet.

% R_AB = (((2R||2R + R) || 2R) + 2R) || 2R
R_AB = p((p((p(R,2*R) + R), R) + R) ,R)

% R_CD = (2R||2R) || (R + 2R||4R)
R_CD = p( p(R, 2*R), R + p(R, 2*R) )
