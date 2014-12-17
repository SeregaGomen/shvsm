#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <math.h>
#include "shvsmintegralcreatedialog.h"
#include "printreportdialog.h"
#include "ui_shvsmintegralcreatedialog.h"


void getIS(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 920, 1320, 1380, 1390, 1440, 1500, 2800 },
                       { 1119, 1629, 1679, 1779, 1819, 1939, 3500 },
                       { 1520, 2270, 2330, 2600, 3350, 4080, 4901 },
                       { 1720, 2600, 2650, 2950, 4110, 5280, 5600 }},
          m[4][7]   = {{ 770, 1100, 1150, 1160, 1200, 1250, 1800 },
                       { 935, 1359, 1410, 1480, 1515, 1620, 2500 },
                       { 1265, 1890, 1940, 2130, 2790, 3400, 3901 },
                       { 1720, 2600, 2650, 2950, 4110, 5280, 4600 }},
          w_s[4][7] = {{ 680, 925, 1000, 1000, 1080, 1080, 2300 },
                       { 819, 1099, 1199, 1319, 1379, 1439, 3000 },
                       { 1300, 1470, 1800, 1900, 2050, 2050, 4401 },
                       { 1540, 1650, 2100, 2220, 2400, 2460, 5100 }},
          w[4][7] =   {{ 570, 770, 865, 865, 900, 900, 800 },
                       { 680, 925, 1010, 1100, 1150, 1200, 1500 },
                       { 1080, 1225, 1500, 1590, 1700, 1700, 2901 },
                       { 1280, 1380, 1745, 1850, 2000, 2050, 3600 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}


void getIG(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 0.209, 0.209, 0.209, 0.288, 0.288, 0.317, 0.52 },
                       { 0.209, 0.209, 0.209, 0.335, 0.335, 0.389, 0.609 },
                       { 0.508, 0.508, 0.508, 0.570, 0.570, 0.576, 0.787 },
                       { 0.568, 0.568, 0.568, 0.630, 0.630, 0.632, 0.884 }},
          m[4][7]   = {{ 0.160, 0.160, 0.160, 0.240, 0.240, 0.264, 0.32 },
                       { 0.169, 0.169, 0.169, 0.279, 0.279, 0.324, 0.409 },
                       { 0.423, 0.423, 0.423, 0.475, 0.475, 0.480, 0.587 },
                       { 0.473, 0.473, 0.473, 0.525, 0.525, 0.552, 0.674 }},
          w_s[4][7] = {{ 0.139, 0.139, 0.139, 0.179, 0.179, 0.239, 0.42 },
                       { 0.189, 0.189, 0.189, 0.233, 0.233, 0.239, 0.509 },
                       { 0.469, 0.469, 0.469, 0.492, 0.492, 0.508, 0.687 },
                       { 0.520, 0.520, 0.520, 0.552, 0.552, 0.568, 0.774 }},
          w[4][7] =   {{ 0.116, 0.116, 0.116, 0.149, 0.149, 0.150, 0.26 },
                       { 0.157, 0.157, 0.157, 0.194, 0.194, 0.199, 0.369 },
                       { 0.391, 0.391, 0.391, 0.410, 0.410, 0.423, 0.547 },
                       { 0.433, 0.433, 0.433, 0.460, 0.460, 0.473, 0.634 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}


void getKEK(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 1800, 1800, 1800, 1700, 1700, 1600, 1600 },
                       { 2199, 2199, 2199, 2099, 2099, 1999, 2000 },
                       { 3000, 3000, 3000, 2900, 2900, 2800, 2801 },
                       { 3400, 3400, 3400, 3300, 3300, 3200, 3200}},
          m[4][7]   = {{ 2200, 2200, 2200, 2100, 2200, 2000, 2900 },
                       { 2599, 2599, 2599, 2499, 2499, 2399, 2400 },
                       { 3400, 3400, 3400, 3300, 3300, 3200, 3201},
                       { 3800, 3800, 3800, 3700, 3700, 3600, 3600 }},
          w_s[4][7] = {{ 2000, 2000, 2000, 1900, 1900, 1800, 1800 },
                       { 2399, 2399, 2399, 2299, 2299, 2199, 2200 },
                       { 3200, 3200, 3200, 3100, 3100, 3000, 3001 },
                       { 3600, 3600, 3600, 3500, 3500, 3400, 3400 }},
          w[4][7] =   {{ 2400, 2400, 2400, 2300, 2300, 2200, 2200 },
                       { 2799, 2799, 2799, 2699, 2699, 2599, 2600 },
                       { 4000, 4000, 4000, 3900, 3900, 3800, 3401 },
                       { 4000, 4000, 4000, 3900, 3900, 3800, 3800 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}


void getIR(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 65, 65, 65, 65, 65, 65, 56 },
                       { 71, 74, 74, 75, 75, 75, 66 },
                       { 95, 103, 103, 102, 102, 102, 93 },
                       { 102, 112, 111, 111, 111, 111, 98 }},
          m[4][7]   = {{ 70, 70, 70, 70, 70, 70, 66 },
                       { 76, 79, 79, 80, 80, 80, 76 },
                       { 100, 108, 108, 107, 107, 107, 103 },
                       { 107, 117, 116, 115, 114, 114, 108 }},
          w_s[4][7] = {{ 70, 70, 70, 70, 70, 70, 56 },
                       { 75, 78, 78, 78, 79, 79, 66 },
                       { 99, 107, 107, 106, 106, 106, 98 },
                       { 116, 116, 115, 115, 115, 115, 103 }},
          w[4][7] =   {{ 75, 75, 75, 75, 75, 75, 68 },
                       { 79, 86, 89, 89, 89, 89, 78 },
                       { 109, 109, 109, 104, 104, 104, 105 },
                       { 124, 124, 118, 116, 116, 116, 110 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}

void getVC(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 360, 420, 470, 550, 600, 680, 825 },
                       { 389, 449, 509, 579, 639, 719, 879 },
                       { 450, 510, 570, 640, 720, 800, 990 },
                       { 480, 540, 600, 670, 760, 840, 1045 }},
          m[4][7]   = {{ 340, 400, 460, 510, 580, 640, 680 },
                       { 369, 429, 489, 549, 609, 669, 680 },
                       { 430, 490, 550, 610, 670, 730, 800 },
                       { 460, 520, 580, 640, 700, 760, 800 }},
          w_s[4][7] = {{ 390, 450, 515, 570, 610, 645, 720 },
                       { 419, 479, 439, 589, 629, 669, 759 },
                       { 480, 540, 590, 630, 670, 720, 840 },
                       { 510, 570, 616, 650, 690, 745, 880 }},
          w[4][7] =   {{ 370, 430, 490, 500, 530, 550, 500 },
                       { 399, 459, 519, 529, 559, 579, 539 },
                       { 460, 520, 580, 590, 620, 640, 620 },
                       { 490, 550, 610, 620, 650, 670, 620 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}

void getOPSS(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 600, 600, 700, 700, 800, 800, 800 },
                       { 999, 999, 1099, 1099, 1119, 1119, 1199 },
                       { 1800, 1800, 1900, 1900, 2000, 2000, 2000 },
                       { 2200, 2200, 2300, 2300, 2400, 2400, 2400 }},
          m[4][7]   = {{ 800, 800, 900, 900, 1000, 1000, 1000 },
                       { 1199, 1199, 1299, 1299, 1319, 1319, 1399 },
                       { 2400, 2400, 2500, 2500, 2600, 2600, 2200 },
                       { 2400, 2400, 2500, 2500, 2600, 2600, 2600 }},
          w_s[4][7] = {{ 700, 700, 800, 800, 900, 900, 900 },
                       { 1099, 1099, 1199, 1199, 1219, 1219, 1299 },
                       { 1900, 1900, 2000, 2000, 2100, 2100, 2100 },
                       { 2300, 2300, 2400, 2400, 2500, 2500, 2500 }},
          w[4][7] =   {{ 1000, 1000, 1100, 1100, 1200, 1200, 1200 },
                       { 1399, 1399, 1499, 1499, 1599, 1599, 1599 },
                       { 2200, 2200, 2300, 2300, 2400, 2400, 2400 },
                       { 2600, 2600, 2700, 2700, 2800, 2800, 2800 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}

void getMOK(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 2.5, 2.8, 3.1, 3.4, 3.7, 4.19, 4.50 },
                       { 2.69, 2.99, 3.29, 3.59, 3.89, 4.19, 5.49 },
                       { 2.9, 3.2, 3.5, 3.8, 4.1, 5.2, 7.50 },
                       { 3.1, 3.4, 3.7, 4.0, 4.3, 5.4, 8.50 }},
          m[4][7]   = {{ 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.0 },
                       { 2.59, 2.79, 2.99, 3.19, 3.39, 3.59, 3.99 },
                       { 2.8, 3.0, 3.2, 3.4, 3.6, 4.6, 6.00 },
                       { 3.0, 3.2, 3.4, 3.6, 3.8, 4.8, 7.00 }},
          w_s[4][7] = {{ 2.5, 2.7, 2.9, 3.1, 3.3, 3.4, 3.50 },
                       { 2.69, 2.89, 3.09, 3.29, 3.49, 3.69, 4.49 },
                       { 2.9, 3.1, 3.3, 3.5, 3.7, 4.7, 6.50 },
                       { 3.1, 3.3, 3.5, 3.7, 3.9, 4.9, 7.50 }},
          w[4][7] =   {{ 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.50 },
                       { 2.59, 2.69, 2.79, 2.89, 2.99, 3.09, 3.49 },
                       { 2.8, 2.9, 3.0, 3.1, 3.2, 4.1, 5.50 },
                       { 3.0, 3.1, 3.2, 3.3, 3.4, 4.3, 6.50 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}

void getSOK(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 12) ? 0 : age - 12;
    float m_s[4][7] = {{ 36, 40.5, 44.5, 48, 51.5, 54, 50 },
                       { 38.4, 41.9, 46.4, 50.4, 53.9, 57.4, 59.99 },
                       { 42, 45.5, 49, 53, 56.5, 72, 80 },
                       { 44.5, 48, 51.5, 54.5, 59, 75.5, 90 }},
          m[4][7]   = {{ 30, 34, 37, 40, 43, 45, 40 },
                       { 31.9, 35.9, 38.9, 43.9, 44.9, 47.9, 44.99 },
                       { 35, 38, 41, 44, 47, 60, 70 },
                       { 37, 40, 43, 46, 49, 63, 80}},
          w_s[4][7] = {{ 36, 37.5, 41, 44, 46.5, 48, 45 },
                       { 38.4, 38.9, 42.9, 46.4, 48.9, 51.4, 54.99 },
                       { 42, 42.5, 45.5, 49, 51.5, 66, 75 },
                       { 44.5, 45, 48, 50.5, 53, 69.5, 85 }},
          w[4][7] =   {{ 30, 32, 35.5, 37, 39.5, 41, 39.50 },
                       { 31.9, 33.9, 36.4, 40.9, 41.4, 43.9, 48.49 },
                       { 35, 36, 38.5, 41, 43.5, 56, 66.50 },
                       { 37, 38, 40.5, 43, 45.5, 59, 75.50 }},
          (*arr)[7];

    if (age >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[0][index];
    val2 = arr[1][index];
    val3 = arr[2][index];
    val4 = arr[3][index];
}

float normalize(float p)
{
    if (p < 0)
        p = 0;
    else if (p > 100)
        p = 100;
    return p;
}

float SHVSMIntegralCreateDialog::nDEV_GEL(float val)
{
    return normalize(fabs(100.0*((20.0 - fabs(val)) - 1.0/20.0)));
}

float SHVSMIntegralCreateDialog::nSI(float val)
{
    return normalize(100.0*(fabs((4.0 - val)/4.0 - 1.0)));
}

float SHVSMIntegralCreateDialog::nIR(float val)
{
    float ret;

    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                ret = normalize(100.0*((120.0 - val)/80.0 - 1.0));
            else
                ret = normalize(100.0*((125.0 - val)/80.0 - 1.0));
        }
        else
        {
            if (sex == 1)
                ret = normalize(100.0*((130.0 - val)/85.0 - 1.0));
            else
                ret = normalize(100.0*((135.0 - val)/80.0 - 1.0));
        }
    }
    else
    {
        if (sex == 1)
            ret = normalize(100.0*((130.0 - val)/80.0 - 1.0));
        else
            ret = normalize(100.0*((130.0 - val)/90.0 - 1.0));
    }
    return ret;
}

float SHVSMIntegralCreateDialog::nOADC(float val)
{
    if (old < 18)
        return normalize(100.0*((20.0 - val)/20.0 - 1.0));
    else
        return normalize(100.0*((30.0 - val)/30.0 - 1.0));
}

float SHVSMIntegralCreateDialog::nOADD(float val)
{
    if (old < 18)
        return normalize(100.0*((20.0 - val)/20.0 - 1.0));
    else
        return normalize(100.0*((30.0 - val)/30.0 - 1.0));
}

float SHVSMIntegralCreateDialog::nDTBE(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[][2] = {{ 35, 15 },
                      { 39, 15 },
                      { 43, 17 },
                      { 47, 17 },
                      { 51, 19 },
                      { 55, 20 },
                      { 80, 50 }},
          m[][2] =   {{ 25, 10 },
                      { 28, 13 },
                      { 31, 14 },
                      { 37, 19 },
                      { 40, 21 },
                      { 45, 24 },
                      { 65, 50}},
          w_s[][2] = {{ 30, 15 },
                      { 33, 15 },
                      { 36, 16 },
                      { 39, 17 },
                      { 42, 18 },
                      { 45, 20 },
                      { 70, 40}},
          w[][2]   = {{ 25, 15 },
                      { 26, 15 },
                      { 27, 15 },
                      { 28, 15 },
                      { 29, 15 },
                      { 30, 15 },
                      { 55, 40 }},
          (*arr)[2];

    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nDTE(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[][2] = {{ 40, 20 },
                      { 45, 20 },
                      { 50, 25 },
                      { 55, 25 },
                      { 60, 25 },
                      { 70, 25 },
                      { 100, 70 }},
          m[][2] =   {{ 35, 20 },
                      { 40, 20 },
                      { 42, 20 },
                      { 45, 20 },
                      { 50, 20 },
                      { 55, 20 },
                      { 85, 65 }},
          w_s[][2] = {{ 40, 25 },
                      { 44, 25 },
                      { 48, 25 },
                      { 52, 25 },
                      { 56, 25 },
                      { 60, 25 },
                      { 90, 60 }},
          w[][2]   = {{ 30, 15 },
                      { 33, 15 },
                      { 36, 17 },
                      { 39, 18 },
                      { 42, 20 },
                      { 45, 20 },
                      { 75, 60 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nIS(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[][2] = {{ 1850, 1000 },
                      { 2800, 1800 },
                      { 2900, 1800 },
                      { 3100, 2000 },
                      { 4300, 2200 },
                      { 5800, 4700 },
                      { 6000, 3600 }},
          m[][2] =   {{ 1500, 1000 },
                      { 2500, 1800 },
                      { 2600, 1800 },
                      { 2700, 2000 },
                      { 3700, 2800 },
                      { 4900, 4000 },
                      { 5500, 3100 }},
          w_s[][2] = {{ 1700, 1000 },
                      { 1750, 1000 },
                      { 2200, 1400 },
                      { 2400, 1500 },
                      { 2700, 1900 },
                      { 2800, 1950 },
                      { 5500, 3100}},
          w[][2]   = {{ 1400, 1000 },
                      { 1500, 1000 },
                      { 1900, 1300 },
                      { 2000, 1300 },
                      { 2200, 1500 },
                      { 2500, 1700 },
                      { 4400, 3800 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nIG(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[][2] = {{ 0.65, 0.5 },
                      { 0.65, 0.5 },
                      { 0.65, 0.5 },
                      { 0.7, 0.5 },
                      { 0.7, 0.5 },
                      { 0.75, 0.5 },
                      { 0.95, 0.55 }},
          m[][2] =   {{ 0.55, 0.45 },
                      { 0.55, 0.45 },
                      { 0.55, 0.45 },
                      { 0.6, 0.45 },
                      { 0.6, 0.45 },
                      { 0.65, 0.45 },
                      { 0.75, 0.41 }},
          w_s[][2] = {{ 0.6, 0.5 },
                      { 0.6, 0.5 },
                      { 0.6, 0.5 },
                      { 0.65, 0.5 },
                      { 0.65, 0.5 },
                      { 0.7, 0.55 },
                      { 0.85, 0.5 }},
          w[][2]   = {{ 0.55, 0.5 },
                      { 0.55, 0.5 },
                      { 0.55, 0.5 },
                      { 0.6, 0.5 },
                      { 0.6, 0.5 },
                      { 0.65, 0.5 },
                      { 0.68, 0.44 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nGEL(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[][2] = {{ 3000, 1500 },
                      { 3500, 1500 },
                      { 4000, 2000 },
                      { 4500, 2000 },
                      { 5000, 2500 },
                      { 5500, 2500 },
                      { 5500, 3500 }},
          m[][2] =   {{ 3000, 1500 },
                      { 3500, 2000 },
                      { 3500, 1500 },
                      { 4000, 2000 },
                      { 4500, 2000 },
                      { 5000, 2500 },
                      { 5000, 3000 }},
          w_s[][2] = {{ 2900, 1500 },
                      { 3400, 1500 },
                      { 3800, 2000 },
                      { 4200, 2000 },
                      { 4800, 2500 },
                      { 5200, 2500 },
                      { 5000, 3000}},
          w[][2]   = {{ 2900, 1500 },
                      { 3300, 2000 },
                      { 3400, 1500 },
                      { 3600, 2000 },
                      { 4000, 2000 },
                      { 4500, 2500 },
                      { 4000, 2500}},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}


float SHVSMIntegralCreateDialog::nKEK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[7][2] = {{ 3800, 2000 },
                       { 3800, 2000 },
                       { 3800, 2000 },
                       { 3700, 2200 },
                       { 3700, 2200 },
                       { 3600, 2400 },
                       { 3600, 2400 }},
          m[7][2] =   {{ 4000, 2000 },
                       { 4000, 2000 },
                       { 4000, 2000 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4400, 2600 },
                       { 4400, 2600 }},
          w_s[7][2] = {{ 4200, 2200 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4000, 2400 },
                       { 4000, 2400 },
                       { 3800, 2400 },
                       { 3800, 2400 }},
          w[7][2]   = {{ 4000, 2000 },
                       { 4000, 2000 },
                       { 4000, 2000 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4600, 2600 },
                       { 4600, 2600 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*((arr[index][0] - val)/arr[index][1] - 1.0));
}

float SHVSMIntegralCreateDialog::nOPSS(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[7][2] = {{ 2400, 2000 },
                       { 2400, 2000 },
                       { 2400, 2000 },
                       { 2600, 2200 },
                       { 2600, 2200 },
                       { 2800, 2400 },
                       { 2800, 2400 }},
          m[7][2] =   {{ 2600, 2000 },
                       { 2600, 2000 },
                       { 2600, 2000 },
                       { 2600, 2200 },
                       { 2600, 2200 },
                       { 2800, 2400 },
                       { 3000, 2400 }},
          w_s[7][2] = {{ 2500, 2000 },
                       { 2500, 2000 },
                       { 2500, 2000 },
                       { 2600, 2000 },
                       { 2600, 2000 },
                       { 2900, 2500 },
                       { 2900, 2500 }},
          w[7][2]   = {{ 2800, 2000 },
                       { 2800, 2000 },
                       { 2800, 2000 },
                       { 2900, 2000 },
                       { 2900, 2000 },
                       { 2900, 2500 },
                       { 3200, 2400 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*((arr[index][0] - val)/arr[index][1] - 1.0));
}

float SHVSMIntegralCreateDialog::nVC(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[7][2] = {{ 520, 200 },
                       { 570, 200 },
                       { 640, 200 },
                       { 710, 200 },
                       { 800, 220 },
                       { 880, 240 },
                       { 1200, 700 }},
          m[7][2] =   {{ 500, 200 },
                       { 550, 200 },
                       { 620, 210 },
                       { 680, 210 },
                       { 740, 210 },
                       { 750, 220 },
                       { 900, 600 }},
          w_s[7][2] = {{ 540, 200 },
                       { 600, 200 },
                       { 650, 200 },
                       { 700, 200 },
                       { 730, 210 },
                       { 780, 210 },
                       { 1000, 700 }},
          w[7][2]   = {{ 520, 200 },
                       { 580, 200 },
                       { 620, 200 },
                       { 660, 200 },
                       { 710, 220 },
                       { 730, 220 },
                       { 800, 650 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nMOK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[7][2] = {{ 3.5, 2.0 },
                       { 4.0, 2.5 },
                       { 4.5, 2.5 },
                       { 5, 2.5 },
                       { 5.5, 2.5 },
                       { 6, 3 },
                       { 10, 7 }},
          m[7][2] =   {{ 3.5, 2 },
                       { 4, 2.5 },
                       { 4, 2 },
                       { 4.5, 2.5 },
                       { 5, 2.5 },
                       { 5.5, 3 },
                       { 9, 7 }},
          w_s[7][2] = {{ 3.5, 2.0 },
                       { 3.5, 2.0 },
                       { 4, 2 },
                       { 4.5, 2 },
                       { 5, 2.5 },
                       { 5.5, 2.5 },
                       { 8, 5 }},
          w[7][2]   = {{ 3.5, 2 },
                       { 3.5, 2 },
                       { 4, 2.5 },
                       { 4, 2.5 },
                       { 4.5, 2.5 },
                       { 5, 3 },
                       { 7, 5}},
         (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}

float SHVSMIntegralCreateDialog::nSOK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[7][2] = {{ 50, 20 },
                       { 50, 20 },
                       { 55, 25 },
                       { 65, 35 },
                       { 75, 40 },
                       { 85, 40 },
                       { 100, 60 }},
          m[7][2] =   {{ 45, 25 },
                       { 45, 25 },
                       { 50, 25 },
                       { 55, 25 },
                       { 60, 25 },
                       { 75, 40 },
                       { 90, 60 }},
          w_s[7][2] = {{ 50, 20 },
                       { 50, 20 },
                       { 55, 25 },
                       { 60, 25 },
                       { 65, 30 },
                       { 70, 35 },
                       { 90, 55 }},
          w[7][2]   = {{ 45, 25 },
                       { 45, 25 },
                       { 50, 25 },
                       { 55, 25 },
                       { 60, 30 },
                       { 65, 35 },
                       { 85, 55 }},
          (*arr)[2];


    if (old >= 18)
        index = 6;
    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    return normalize(100.0*(1.0 - (arr[index][0] - val)/arr[index][1]));
}


void SHVSMIntegralCreateDialog::IS(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getIS(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV11,ui->labelT11,val,val1,val2,val3,val4);
}


void SHVSMIntegralCreateDialog::IG(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getIG(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV10,ui->labelT10,val,val1,val2,val3,val4);
}

void SHVSMIntegralCreateDialog::KEK(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getKEK(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV7,ui->labelT7,val,val1,val2,val3,val4);
}

void SHVSMIntegralCreateDialog::IR(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getIR(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV6,ui->labelT6,val,val1,val2,val3,val4);
}

void SHVSMIntegralCreateDialog::SOK(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getSOK(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV1,ui->labelT1,val,val1,val2,val3,val4);
}


void SHVSMIntegralCreateDialog::MOK(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getMOK(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV2,ui->labelT2,val,val1,val2,val3,val4);
}

void SHVSMIntegralCreateDialog::OPSS(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getOPSS(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV4,ui->labelT4,val,val1,val2,val3,val4);
}

void SHVSMIntegralCreateDialog::VC(float val)
{
    float val1,
          val2,
          val3,
          val4;

    getVC(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicatorTxt(ui->labelV5,ui->labelT5,val,val1,val2,val3,val4);
}

SHVSMIntegralCreateDialog::SHVSMIntegralCreateDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SHVSMIntegralCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

SHVSMIntegralCreateDialog::~SHVSMIntegralCreateDialog()
{
    delete ui;
    delete model;
}

void SHVSMIntegralCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void SHVSMIntegralCreateDialog::setupForm(void)
{
    QString query = "SELECT surveyed.id, surveyed.name,team.name,sex.name,qualification.name,surveyed.DOB,sex_id,qualification_id \
            FROM surveyed \
            LEFT OUTER JOIN team ON surveyed.team_id = team.id \
            LEFT OUTER JOIN sex ON surveyed.sex_id = sex.id \
            LEFT OUTER JOIN qualification ON surveyed.qualification_id = qualification.id";

    ui->pbSave->setEnabled(false);
    ui->pbPrint->setEnabled(false);

    // Задание цвета легенды
    // "Низкий" - красный
    ui->labelLow->setStyleSheet("QLabel { background-color : red; }");
    // "Ниже среднего" - серый
    ui->labelBAverage->setStyleSheet("QLabel { background-color : gray; }");
    // "Cредний" - желтый
    ui->labelAverage->setStyleSheet("QLabel { background-color : yellow; }");
    // "Выше среднего" - бирюзовый
    ui->labelAAverage->setStyleSheet("QLabel { background-color : aqua; }");
    // "Вышсокий" - лайм
    ui->labelHigh->setStyleSheet("QLabel { background-color : lime; }");

    // Текущая дата
    ui->deDate->setDate(QDate::currentDate());


    // Список обследуемых
    model = new QSqlQueryModel(this);
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team"));
    model->setHeaderData(3, Qt::Horizontal, tr("Sex"));
    model->setHeaderData(4, Qt::Horizontal, tr("Status"));
    model->setHeaderData(5, Qt::Horizontal, tr("DOB"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->resizeSection(2, 60);
    ui->tableView->horizontalHeader()->resizeSection(3, 60);
    ui->tableView->horizontalHeader()->resizeSection(4, 95);
    ui->tableView->horizontalHeader()->resizeSection(5, 95);
    ui->tableView->setWordWrap(true);

    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());

    ui->tableView->setCurrentIndex(ui->tableView->model()->index(0, 0));
}

void SHVSMIntegralCreateDialog::slotCalcSHVSMIntegral(void)
{
    bool isOk;
    QString dob = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();

    sex = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),6)).toInt();
    isSportsman = (ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),7)).toInt() == 1) ? true : false;
    if (ui->leWeight->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this, tr("Error"),tr("Do not set the 'Weight'!"), QMessageBox::Ok);
        ui->leWeight->setFocus();
        return;
    }
    weight = ui->leWeight->text().toFloat(&isOk);
    if (!isOk || weight <= 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Weight'!"), QMessageBox::Ok);
        ui->leWeight->setFocus();
        return;
    }
    if (ui->leGrowth->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this, tr("Error"),tr("Do not set the 'Height'!"), QMessageBox::Ok);
        ui->leGrowth->setFocus();
        return;
    }
    growth = ui->leGrowth->text().toFloat(&isOk);
    if (!isOk || growth <= 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Height'!"), QMessageBox::Ok);
        ui->leGrowth->setFocus();
        return;
    }

    hr = ui->leHR->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Heart rate'!"), QMessageBox::Ok);
        ui->leHR->setFocus();
        return;
    }

    sbp = ui->leSBP->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Systolic blood pressure'!"), QMessageBox::Ok);
        ui->leSBP->setFocus();
        return;
    }

    dbp = ui->leDBP->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Diastolic blood pressure'!"), QMessageBox::Ok);
        ui->leDBP->setFocus();
        return;
    }

    lvActual = ui->leLActual->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Actual vital capacity of lungs'!"), QMessageBox::Ok);
        ui->leLActual->setFocus();
        return;
    }

    dte = ui->leDTE->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Delay time exhalations'!"), QMessageBox::Ok);
        ui->leDTE->setFocus();
        return;
    }

    dtbe = ui->leDTBE->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Delay time breathing exhalation'!"), QMessageBox::Ok);
        ui->leDTBE->setFocus();
        return;
    }

    // Определяем возраст человека
    old = QDate::currentDate().year() - dob.right(4).toInt();
    if (old <= 0 || old > 120)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the birthday or date survey!"), QMessageBox::Ok);
        return;
    }

    // ------------------------------ 1. СОК ----------------------------------------
    sok = 0.53*sbp + 0.617*growth + 0.231*weight - 1.07*dbp - 0.698*old - 22.64;
    SOK(sok);
    // ------------------------------ 2. МОК ----------------------------------------
    mok = hr*sok/1000.0;
    MOK(mok);
    // ------------------------------ 3. СИ ----------------------------------------
    si = mok/(pow(weight,0.425)*pow(growth,0.725)*0.007184);
    ui->labelV3->setText(QString("%1").arg(si,0,'f',2));
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                if (si < 2.7)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 2.7 && si <= 3.2)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
            else
            {
                if (si < 3.0)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 3.0 && si <= 3.5)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
        }
        else
        {
            if (sex == 1)
            {
                if (si < 3.0)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 3.0 && si <= 3.5)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
            else
            {
                if (si < 3.2)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 3.2 && si <= 3.6)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
        }
    }
    else
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                if (si < 2.5)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 2.5 && si <= 3.0)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
            else
            {
                if (si < 2.7)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 2.7 && si <= 3.2)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
        }
        else
        {
            if (sex == 1)
            {
                if (si < 3.0)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 3.0 && si <= 3.5)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
            else
            {
                if (si < 3.2)
                    ui->labelT3->setText(tr("Hypokinetic type of regulation"));
                else if (si >= 3.2 && si <= 3.6)
                    ui->labelT3->setText(tr("Norm"));
                else
                    ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
            }
        }
    }
    // ------------------------------ 4. ОПСС ----------------------------------------
    opss = ((dbp + 0.33*(sbp - dbp))*1333*60)/(mok*1000);
    OPSS(opss);
    // ------------------------------ 5. VC ----------------------------------------
    vc = 40.0*pow(1000.0*weight/growth,0.5);
    VC(vc);

    // ------------------------------ 6. ИР ----------------------------------------
    ir = hr*sbp/100;
    IR(ir);
    // ------------------------------ 7. КЭК ----------------------------------------
    kek = hr*(sbp - dbp);
    KEK(kek);
    // ------------------------------ 8. ОАДС ----------------------------------------
    if (old >= 18)
    {
        if (sex == 1)
            oadc = sbp - (91 + 0.5*old + 0.1*weight);
        else
            oadc = sbp - (88 + 0.7*old + 0.15*weight);

        ui->labelV8->setText(QString("%1").arg(oadc,0,'f',2));
        if (oadc < 0)
            ui->labelT8->setText(tr("Below the norm"));
        else if (oadc >=0 && oadc <= 30)
            ui->labelT8->setText(tr("Norm"));
        else
            ui->labelT8->setText(tr("Above norm"));
    }
    else
    {
        if (sex == 1)
            oadc = sbp - (95 + 0.5*old + 0.1*weight);
        else
            oadc = sbp - (92 + 0.7*old + 0.15*weight);

        ui->labelV8->setText(QString("%1").arg(oadc,0,'f',2));
        if (oadc < 0)
            ui->labelT8->setText(tr("Below the norm"));
        else if (oadc >=0 && oadc <= 20)
            ui->labelT8->setText(tr("Norm"));
        else
            ui->labelT8->setText(tr("Above norm"));
    }

    // ------------------------------ 9. ОАДД ----------------------------------------
    if (old >= 18)
    {
        if (sex == 1)
            oadd = dbp - (58 + 0.1*old + 0.15*weight);
        else
            oadd = dbp - (62 + 0.17*old + 0.1*weight);

        ui->labelV9->setText(QString("%1").arg(oadd,0,'f',2));
        if (oadd < 0)
            ui->labelT9->setText(tr("Below the norm"));
        else if (oadd >=0 && oadd <= 30)
            ui->labelT9->setText(tr("Norm"));
        else
            ui->labelT9->setText(tr("Above norm"));
    }
    else
    {
        if (sex == 1)
            oadd = dbp - (58 + 0.1*old + 0.15*weight);
        else
            oadd = dbp - (56 + 0.17*old + 0.1*weight);

        ui->labelV9->setText(QString("%1").arg(oadd,0,'f',2));
        if (oadd < 0)
            ui->labelT9->setText(tr("Below the norm"));
        else if (oadd >=0 && oadd <= 20)
            ui->labelT9->setText(tr("Norm"));
        else
            ui->labelT9->setText(tr("Above norm"));
    }

    // -------------------------------- ДЖЕЛ ----------------------------------------
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                dgel = (27.63 - 0.122*old)*growth;
            else
                dgel = (21.78 - 0.101*old)*growth;
        }
        else
        {
            if (sex == 1)
                dgel = (27.63 - 0.122*old)*growth - 500;
            else
                dgel = (21.78 - 0.101*old)*growth - 300;
        }
        ui->leLNorm->setText(QString("%1").arg(dgel,0,'f',2));
    }
    else
    {
        if (sex == 1)
            dgel = 40*growth + 30*weight - 5100;
        else
            dgel = 40*growth + 10*weight - 4400;
        ui->leLNorm->setText(QString("%1").arg(dgel,0,'f',2));
    }
    // -------------------------------- ОтклЖЕЛ ----------------------------------------
    dev_dgel = ((lvActual - dgel)/lvActual)*100;
    ui->leLDeviation->setText(QString("%1").arg(dev_dgel,0,'f',2));
    if (isSportsman)
    {
        if (sex == 1)
        {
            if (dev_dgel < -7.5)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -7.5 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 14.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 15 && dev_dgel <= 25)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
        else
        {
            if (dev_dgel < -10)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -10 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 9.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 10 && dev_dgel <= 20)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
    }
    else
    {
        if (sex == 1)
        {
            if (dev_dgel < -15)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -15 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 7.49)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 7.5 && dev_dgel <= 10.75)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
        else
        {
            if (dev_dgel < -17.5)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -17.5 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 4.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 5 && dev_dgel <= 10)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
    }

    // ------------------------------ 10. ИГ ----------------------------------------
    ig = dtbe/hr;
    IG(ig);


    // ------------------------------ 11. ИC ----------------------------------------
    is = lvActual*dte/hr;
    IS(is);

    // ------------------------------ 12. УФСС ----------------------------------------
    p_sok = nSOK(sok);
    p_mok = nMOK(mok);
    p_oadc = nOADC(oadc);
    p_oadd = nOADD(oadd);
    p_vc = nVC(vc);
    p_opss = nOPSS(opss);
    p_ir = nIR(ir);
    p_kek = nKEK(kek);
    p_si = nSI(si);
    ufss = normalize((p_sok + p_mok + p_oadc + p_oadd + p_vc + p_opss + p_ir + p_kek + p_si)/9.0);
    showIndicatorTxt(ui->labelV12,ui->labelT12,ufss,33.0,49.6,66.1,82.6);

    // ------------------------------ 13. УФСВД ----------------------------------------
    p_dgel = nGEL(dgel);
    p_ig = nIG(ig);
    p_is = nIS(is);
    p_dte = nDTE(dte);
    p_dtbe = nDTBE(dte);
    p_dev_dgel =nDEV_GEL(dev_dgel);

    ufsvd = normalize((p_dgel + p_ig + p_is + p_dte + p_dtbe + p_dev_dgel)/6.0);
    showIndicatorTxt(ui->labelV13,ui->labelT13,ufsvd,33.0,49.6,66.1,82.6);

    ui->pbSave->setEnabled(true);
    ui->pbPrint->setEnabled(true);
}

void SHVSMIntegralCreateDialog::slotSaveSHVSMIntegral(void)
{
    QSqlQuery query;
    QString dt = ui->deDate->text();
    int surveyed_id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();

    // Проверяем, есть ли уже такая запись
    if (!query.exec(QString("SELECT * FROM surveySHVSMIntegral WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        qDebug() << query.lastError();
        return;
    }
    if (query.next())
    {
        // Такая запись уже есть, перезаписываем ее
        if (!query.exec(QString("UPDATE surveySHVSMIntegral SET weight=%3,growth=%4,HR=%5,SAD=%6,DAD=%7,VL=%8,VLN=%9,VLD=%10,T1=%11,T2=%12,V1=%13,V2=%14,V3=%15,V4=%16,V5=%17,\
                                 V6=%18,V7=%19,V8=%20,V9=%21,V10=%22,V11=%23,V12=%24,V13=%25,old=%26 \
                                 WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                                 arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel,0,'f',2).arg(dev_dgel,0,'f',2).arg(dte).arg(dtbe).arg(sok,0,'f',2).arg(mok,0,'f',2).arg(si,0,'f',2).\
                                 arg(opss,0,'f',2).arg(vc,0,'f',2).arg(ir,0,'f',2).arg(kek,0,'f',2).arg(oadc,0,'f',2).\
                                 arg(oadd,0,'f',2).arg(ig,0,'f',2).arg(is,0,'f',2).arg(ufss,0,'f',2).arg(ufsvd,0,'f',2).arg(old)))
            QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

        return;
    }


    if (!query.exec(QString("INSERT INTO surveySHVSMIntegral (surveyed_id,dt,weight,growth,HR,SAD,DAD,VL,VLN,VLD,T1,T2,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13,old) \
                             VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%26)").arg(surveyed_id).arg(dt).arg(weight).\
                             arg(growth).arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel,0,'f',2).arg(dev_dgel,0,'f',2).arg(dte).arg(dtbe).arg(sok,0,'f',2).arg(mok,0,'f',2).\
                             arg(si,0,'f',2).arg(opss,0,'f',2).arg(vc,0,'f',2).arg(ir,0,'f',2).arg(kek,0,'f',2).arg(oadc,0,'f',2).\
                             arg(oadd,0,'f',2).arg(ig,0,'f',2).arg(is,0,'f',2).arg(ufss,0,'f',2).arg(ufsvd,0,'f',2).arg(old)))
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
}

void SHVSMIntegralCreateDialog::showIndicatorTxt(QLabel* labelF, QLabel* labelT,float indicator,float val1, float val2,float val3, float val4)
{

    if (labelF)
        labelF->setText(QString("%1").arg(indicator,0,'f',2));
    if (indicator < val1)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : red; }");
        labelT->setText(tr("Low"));
        labelT->setStyleSheet("QLabel { background-color : red; }");
    }
    else if (indicator >= val1 && indicator <= val2)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : gray; }");
        labelT->setText(tr("Below the average"));
        labelT->setStyleSheet("QLabel { background-color : gray; }");
    }
    else if (indicator > val2 && indicator <= val3)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : yellow; }");
        labelT->setText(tr("Average"));
        labelT->setStyleSheet("QLabel { background-color : yellow; }");
    }
    else if (indicator > val3 && indicator <= val4)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : aqua; }");
        labelT->setText(tr("Above average"));
        labelT->setStyleSheet("QLabel { background-color : aqua; }");
    }
    else
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : lime; }");
        labelT->setText(tr("High"));
        labelT->setStyleSheet("QLabel { background-color : lime; }");
    }
}

void SHVSMIntegralCreateDialog::showIndicatorTxtI(QLabel* labelF, QLabel* labelT,float indicator,float val1, float val2,float val3, float val4)
{

    if (labelF)
        labelF->setText(QString("%1").arg(indicator,0,'f',2));
    if (indicator > val1)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : red; }");
        labelT->setText(tr("Low"));
        labelT->setStyleSheet("QLabel { background-color : red; }");
    }
    else if (indicator <= val1 && indicator >= val2)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : gray; }");
        labelT->setText(tr("Below the average"));
        labelT->setStyleSheet("QLabel { background-color : gray; }");
    }
    else if (indicator < val2 && indicator >= val3)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : yellow; }");
        labelT->setText(tr("Average"));
        labelT->setStyleSheet("QLabel { background-color : yellow; }");
    }
    else if (indicator < val3 && indicator >= val4)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : aqua; }");
        labelT->setText(tr("Above average"));
        labelT->setStyleSheet("QLabel { background-color : aqua; }");
    }
    else
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : lime; }");
        labelT->setText(tr("High"));
        labelT->setStyleSheet("QLabel { background-color : lime; }");
    }
}

void SHVSMIntegralCreateDialog::slotPrintReport(void)
{
    PrintReportDialog* pdlg = new PrintReportDialog(this);

    genReport(pdlg);
    pdlg->exec();
}

void SHVSMIntegralCreateDialog::genReport(PrintReportDialog* p)
{
    QString text = "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">",
            name = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString(),
            sex_n = (sex == 1) ? tr("M") : tr("W"),
            qualification_n = (isSportsman) ? tr("Athlete") : tr("Non-athlete");

    text += tr("<h1><center>SHVSM-complex express estimation of functional state</center></h1>");
    text += tr("<center>Malikov N.V, Malikova A.N., Svat'ev A.V.<br><b>Examination report</b></center>");
    text += "<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\">";

    text += tr("<tr><td colspan=\"6\">Date of  examination: <b>%1</b></tr>").arg(ui->deDate->text());
    text += tr("<tr><th width=\"200%\">Surname</th><th>Sex</th><th>Age</th><th>Status</th><th>Body<br>length (sm)</th><th>Body<br>mass (kg)</th></tr>");
    text += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td></tr>").arg(name).arg(sex_n).arg(old).arg(qualification_n).arg(ui->leGrowth->text()).arg(ui->leWeight->text());
    text += tr("<tr><th colspan=\"6\">Entrance  calculation data</th></tr>");

    text += tr("<tr><td colspan=\"5\">Heart rate (HR)</td><td>%1</td></tr>").arg(ui->leHR->text().toFloat(),0,'f',0);
    text += tr("<tr><td colspan=\"5\">Systolic arterial pressure (APs)</td><td>%1</td></tr>").arg(ui->leSBP->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Diastolic arterial pressure (APd)</td><td>%1</td></tr>").arg(ui->leDBP->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Vital lung capacity (VLC)</td><td>%1</td></tr>").arg(ui->leLActual->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Inhalation breathing delay time (Tin)</td><td>%1</td></tr>").arg(ui->leDTE->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Exhalation breathing delay time (Tex)</td><td>%1</td></tr>").arg(ui->leDTBE->text().toFloat(),0,'f',2);
    text += tr("<tr><th colspan=\"6\">Calculation data</th></tr>");

    text += tr("<tr><th colspan=\"4\">Index</th><th>Numerical<br>value</th><th>Functional<br>estimation</th></tr>");

    text += tr("<tr><td colspan=\"4\">Systole blood volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV1->text().toFloat(),0,'f',2).arg(ui->labelT1->text());
    text += tr("<tr><td colspan=\"4\">Minute blood volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV2->text().toFloat(),0,'f',2).arg(ui->labelT2->text());
    text += tr("<tr><td colspan=\"4\">Cardiac index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV3->text().toFloat(),0,'f',2).arg(ui->labelT3->text());
    text += tr("<tr><td colspan=\"4\">General peripheral resistance</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV4->text().toFloat(),0,'f',2).arg(ui->labelT4->text());
    text += tr("<tr><td colspan=\"4\">Heart volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV5->text().toFloat(),0,'f',2).arg(ui->labelT5->text());
    text += tr("<tr><td colspan=\"4\">Robinson Index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV6->text().toFloat(),0,'f',2).arg(ui->labelT6->text());
    text += tr("<tr><td colspan=\"4\">Circulation of blood economizing coefficient</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV7->text().toFloat(),0,'f',2).arg(ui->labelT7->text());
    text += tr("<tr><td colspan=\"4\">Systolic arterial pressure deviation</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV8->text().toFloat(),0,'f',2).arg(ui->labelT8->text());
    text += tr("<tr><td colspan=\"4\">Diastolic arterial pressure deviation</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV9->text().toFloat(),0,'f',2).arg(ui->labelT9->text());
    text += tr("<tr><td colspan=\"4\">Hypoxia index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV10->text().toFloat(),0,'f',2).arg(ui->labelT10->text());
    text += tr("<tr><td colspan=\"4\">Skibinsky index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV11->text().toFloat(),0,'f',2).arg(ui->labelT11->text());
    text += tr("<tr><td colspan=\"4\"><b>Cardio-vascular system functional state level</b></td><td>%1</td><td>%2</td></tr>").arg(ui->labelV12->text().toFloat(),0,'f',2).arg(ui->labelT12->text());
    text += tr("<tr><td colspan=\"4\"><b>External breathing system functional state level</b></td><td>%1</td><td>%2</td></tr>").arg(ui->labelV13->text().toFloat(),0,'f',2).arg(ui->labelT13->text());

    text += "</table>";



    p->setText(text);
}

void SHVSMIntegralCreateDialog::slotClear(void)
{
    ui->pbSave->setEnabled(false);
    ui->pbPrint->setEnabled(false);

    ui->leWeight->clear();
    ui->leGrowth->clear();
    ui->leHR->clear();
    ui->leSBP->clear();
    ui->leDBP->clear();
    ui->leDTE->clear();
    ui->leDTBE->clear();

    ui->leLActual->clear();
    ui->leLDeviation->clear();
    ui->leLNorm->clear();

    ui->labelFE->clear();
    ui->labelV1->clear();
    ui->labelT1->clear();
    ui->labelV2->clear();
    ui->labelT2->clear();
    ui->labelV3->clear();
    ui->labelT3->clear();
    ui->labelV4->clear();
    ui->labelT4->clear();
    ui->labelV5->clear();
    ui->labelT5->clear();
    ui->labelV6->clear();
    ui->labelT6->clear();
    ui->labelV7->clear();
    ui->labelT7->clear();
    ui->labelV8->clear();
    ui->labelT8->clear();
    ui->labelV9->clear();
    ui->labelT9->clear();
    ui->labelV10->clear();
    ui->labelT10->clear();
    ui->labelV11->clear();
    ui->labelT11->clear();
    ui->labelV12->clear();
    ui->labelT12->clear();
    ui->labelV13->clear();
    ui->labelT13->clear();

    ui->labelFE->setStyleSheet("QLabel { background-color : ; }");
    ui->labelFE->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV1->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT1->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV2->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT2->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV3->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT3->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV4->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT4->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV5->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT5->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV6->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT6->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV7->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT7->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV8->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT8->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV9->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT9->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV10->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT10->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV11->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT11->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV12->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT12->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV13->setStyleSheet("QLabel { background-color : ; }");
    ui->labelT13->setStyleSheet("QLabel { background-color : ; }");

}

