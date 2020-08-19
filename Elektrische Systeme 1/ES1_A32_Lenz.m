%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterloesung - Aufgabe 32
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule fuer Technik Berlin
%--------------------------------------------------------------
%
% Das uebliche vorgehen
%
clear
close all
home
%
% Definition der zu benutzenden bzw. gegebenen Grössen
%
C = 20e-9;  % in F
L = 180e-6; % in H
R = 3.5;    % in Ohm
I = 10e-3;  % in A
%
% Resonanzfrequenz
%
om_0 = 1/sqrt(L*C); % Thomsonsche-Gleichung, der Kreisfrequenz omega !!
f0 = om_0/(2*pi)    % Angabe der Resonanzfrequenz  
%
% Berechnug des Kennwiderstands
%
Zk = sqrt(L/C)
%
% Berechnug der Guete
%
Q = Zk/R
%
% Berechnug der Bandbreite
%
b = om_0/(2*pi*Q) % Ist natuerlich identisch zu f0/Q
%
% Eckfrequenzen -> Nach Def. Skript ES1_06_Frequenzabhaengigkeit, Seite 10
%
om_p45 = sqrt(om_0^2+(om_0/(2*Q))^2) + om_0/(2*Q)
om_m45 = sqrt(om_0^2+(om_0/(2*Q))^2) - om_0/(2*Q)
%
% Spannungen bei Resonanzfrequenz
% -> Nach Skript ES1_06_Frequenzabhaengigkeit, Seite 16
%
UR = I*R
UL_0 = j*I*Zk
UC_0 = -j*I*Zk
%
% Zusatz: Berechnung des Frequenzganges und Darstellung im Bodediagramm
%
figure(1)
om = logspace(log10(om_0/10), log10(om_0*10),500); % in 1/s
Z = R + j*om*L + 1./(j*om*C);
Betrag = 20*log10(abs(Z/R)); % Betrag in dB 
Phase = 180/pi * angle(Z);   % Phase in deg
subplot(2,1,1)
semilogx(om, Betrag)
grid
title('Amplitudengang')
subplot(2,1,2)
semilogx(om, Phase)
grid
title('Phasengang')
%
% Schoenere Grafik
%
% Zusatz: Berechnung des Frequenzganges und Darstellung im Bodediagramm
%
figure(2)
om = logspace(log10(om_0/10), log10(om_0*10),500); % in 1/s
Z = R + j*om*L + 1./(j*om*C);
Betrag = 20*log10(abs(Z/R)); % Betrag in dB 
Phase = 180/pi * angle(Z);   % Phase in deg
subplot(2,1,1)
set(semilogx(om, Betrag),"linewidth",2)
grid
set(title('Amplitudengang'),"fontsize",18)
xlabel('Kreisfrequenz','FontSize',16,'FontWeight','bold')
ylabel('Amplitudenverhältnis in dB','FontSize',16,'FontWeight','bold')
subplot(2,1,2)
set(semilogx(om, Phase),"linewidth",2)
grid
set(title('Phasengang'),"fontsize",18)
xlabel('Kreisfrequenz','FontSize',16,'FontWeight','bold')
ylabel('Phasengang in Grad','FontSize',16,'FontWeight','bold')
%