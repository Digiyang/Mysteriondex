%--------------------------------------------------------------
% Elektrische Systeme 1 
% Musterloesung - Aufgabe 33
% Prof. Dr.-Ing. V. Sommer, Beuth Hochschule fuer Technik Berlin
%--------------------------------------------------------------
%
% Das uebliche vorgehen
%
clear
close all
home
%
% Definition der in der Aufgabenstellung gegebenen Groessen
%
ZK = 1600;        % in Ohm -> Kennwiderstand
om_0 = 2*pi*10e3; % in 1/s -> Bestimmung der Kreisfrequenz
Q = 80;           % Guete
%
% Berechnug der Groessen siehe Skript ES1_06_Frequenzabhaengigkeit
%
YK = 1/ZK;
G = YK/Q;
R = 1/G
L = 1/(YK*om_0)
C = YK/om_0
b = om_0/(2*pi*Q)
%
% Zusatz: Berechnung des Frequenzganges und Darstellung im Bodediagramm
%
figure(1)
om = logspace(log10(om_0/10), log10(om_0*10),500); % in 1/s
Y = G + 1./(j*om*L) + j*om*C;
Betrag = 20*log10(abs(Y/G)); % in dB
Phase = 180/pi*angle(Y);     % in deg
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
Y = G + 1./(j*om*L) + j*om*C;
Betrag = 20*log10(abs(Y/G)); % in dB
Phase = 180/pi*angle(Y);     % in deg
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