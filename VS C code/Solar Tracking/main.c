/* Solar tracking code to generate position of sun given Time, Latitude and longitude  */
#define _CRT_SECURE_NO_WARNINGS


#include "main.h"

void convert(double hourD) {

	//example 2.88 hours

	double fractPart, hour,m,sec,fractM,fractS,min;
	
	fractM = modf(hourD, &hour); //fractM = 0.88 || hour = 2

	m = fractM * 60; //m = 52.8

	fractS = modf(m, &min);

	sec = (60 * fractS); //constant

	printf("H:M:S - %lf:%lf:%lf\n", hour, min, sec);
}

int main() {

	/*//int year = 2022;
	//int month = 10;
	//int day = 12.416667; //day 12 at 10am
	//scanf("%d", &year);
	//printf("%d \n", year);
	double A = floor(year / 100);
	double JD = floor(tDays * (year + 4716)) + floor(30.6001*(month +1)) + day +2 - A + floor(A/4) - 1524.5;
	double JC = (JD - 2451545) / 365.24218968;
	double L0 = 280.46645 + (360 * JC);
	double m = 357.52910 + 360.0 *((JD - 2451545.0) / 365.25963586);
	double e = 0.016708617 - 0.0000420388 * T;
	double E = atan(sin(m) / (cos(m) - e));
	//double E = 0;
	//E = m + e * sin(E);
	double v = 2* atan(((1 + e) / (1 - e)) * 0.5 * tan(E / 2));
	double Θ = L0 + v - m;
	double Ω = 125.04452 - 19.34177 * JC;
	//double λ = Θ - 0.00569 - 0.00478 * sin(Ω);
	double λ = Θ - 0.00569;
	double ε = 23.439302 - 0.00013 * T + 0.002556 * cos(Ω) + 0.000158 * cos(2*L0);
	double α = atan(cos(ε)*sin(λ) / cos(λ));
	double δ = asin(sin(ε)*sin(λ));
	double ω = L0 - α - 0.0057183 + (hour - 12) * 15 + (l - 2) * 15 - 0.004778 * sin(Ω) - 0.000367*sin(2*L0);
	double h = asin(sin(δ) * sin(φ) + cos(δ) * cos(φ) * cos(ω));
	double Azimuth = asin(cos(δ)*sin(φ) / cos(h));
	printf("Julian date is %f \n", JD);
	printf("%f \n", h);
	printf("%f \n", Azimuth);*/
	int days;
	int month;
	//int GMT;
	double hourD;
	//double l;
	//double φ;
	double φ = 30.004;
	double  l = 31.7003;
	int  GMT = 2;

	//time_t t = time(NULL);
	//printf("\nCurrent date and time is : %s", ctime(&t));
	

	printf("Enter the number of days since the start of the year: ");
	scanf("%d", &days);
	//printf("%d \n", days);
	//printf("Enter the Month: ");
	//scanf("%d", &month);
	//printf("%d \n", month);
	//printf("Enter your time zone in Greenwich Time: ");
	//scanf("%d", &GMT);
	printf("Enter the hour in decimal form: ");
	scanf("%lf", &hourD);
	//printf("%f \n", hour);
	//printf("Enter the Latitude in decimal form: ");
	//scanf("%lf", &φ);
	//("%f \n", l);
	//printf("Enter the Longitude in decimal form: ");
	//scanf("%lf", &l);
	//printf("%f \n", φ);



	while (1) {
		if(hourD < 4.883 || hourD> 19){
			delay(0.4);
			hourD += 0.166667;
			convert(hourD);
			if (hourD >= 24) {
				hourD = 0;
				days += 1;
			}
			continue;
		}
		convert(hourD);
		//The Local Standard Time Meridian (LSTM) is a reference meridian used for a particular time zone and is similar to the Prime Meridian, which is used for Greenwich Mean Time.
		double LSTM = 15 * GMT;

		//B for ease of calculation
		double B = ((double)(360) / (double)(365)) * (days - 81);

		/*The equation of time (EoT) (in minutes) is an empirical equation
		that corrects for the eccentricity of the Earth's orbit and the Earth's axial tilt.*/
		double EoT = 9.87 * sin(2 * B * conv) - 7.53 * cos(B * conv) - 1.5 * sin(B * conv);

		//w1 for ease of calculation
		double w1 = 4 * (l - LSTM);
		//The factor of 4 minutes comes from the fact that the Earth rotates 1° every 4 minutes.

		/*The net Time Correction Factor (in minutes) accounts for the variation of the Local Solar Time (LST)
		within a given time zone due to the longitude variations within the time zone and also incorporates the EoT above.*/
		double TC = EoT + w1;

		//Local Solar Time - is defined as when the sun is highest in the sky
		double LST = hourD + ((double)(TC) / (double)(60));

		/*The Hour Angle converts the local solar time (LST) into the number of degrees which the sun moves across the sky.
		By definition, the Hour Angle is 0° at solar noon. Since the Earth rotates 15° per hour, each hour away from solar noon corresponds to
		an angular motion of the sun in the sky of 15°. In the morning the hour angle is negative, in the afternoon the hour angle is positive.*/
		double HRA = 15 * (LST - 12); // -29.55

		//The declination angle, varies seasonally due to the tilt of the Earth on its axis of rotation and the rotation of the Earth around the sun.
		double declination = 23.45 * sin(B * conv); // -6.95


		/*The elevation angle (used interchangeably with altitude angle) is the angular height of the sun in the sky measured from the horizontal.*/
		double elevation = asin(((sin(declination * conv) * sin(φ * conv)) + (cos(declination * conv) * cos(φ * conv) * cos(HRA * conv)))) * conv2;
		double t1 = sin(declination * conv) * cos(φ * conv);
		double t2 = cos(declination * conv) * sin(φ * conv) * cos(HRA * conv);
		double t3 = cos(elevation * conv);

		//The azimuth angle is like a compass direction with North = 0° and South = 180°. Other authors use a variety of slightly different definitions
		double azimuth = acos((t1 - t2) / t3) * conv2;

		//The zenith angle (ζ) is the angle between the sun and the vertical.
		double zenith = 90 - elevation;
		//printf("Local Solar Time Meridian LSTM = %f \n", LSTM);
		//printf("Equation of Time %f \n", EoT);
		//printf("Time Correction %f \n", TC);
		//printf("Local Solar Time %f \n", LST);
		//printf("declination %f \n", declination);
		//printf("Hour Angle %f \n", HRA);
		printf("Elevation %f \n", elevation);
		printf("Azimuth angle %f \n", azimuth);
		//printf("Zenith angle %f \n", zenith);

		delay(0.4); //step

		hourD += 0.16666667;


		
	}
}