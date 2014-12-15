#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <math.h>
#include "shvsmintegralcreatedialog.h"
#include "printreportdialog.h"
#include "ui_shvsmintegralcreatedialog.h"

float SHVSMIntegralCreateDialog::jDTBE(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 35, 15 },
                       { 39, 15 },
                       { 43, 17 },
                       { 47, 17 },
                       { 51, 19 },
                       { 55, 20 }},
          m[6][2] =   {{ 25, 10 },
                       { 28, 13 },
                       { 31, 14 },
                       { 37, 19 },
                       { 40, 21 },
                       { 45, 24 }},
          w_s[6][2] = {{ 30, 15 },
                       { 33, 15 },
                       { 36, 16 },
                       { 39, 17 },
                       { 42, 18 },
                       { 45, 20 }},
          w[6][2]   = {{ 25, 15 },
                       { 26, 15 },
                       { 27, 15 },
                       { 28, 15 },
                       { 29, 15 },
                       { 30, 15 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jDTE(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 40, 20 },
                       { 45, 20 },
                       { 50, 25 },
                       { 55, 25 },
                       { 60, 25 },
                       { 70, 25 }},
          m[6][2] =   {{ 35, 20 },
                       { 40, 20 },
                       { 42, 20 },
                       { 45, 20 },
                       { 50, 20 },
                       { 55, 20 }},
          w_s[6][2] = {{ 40, 25 },
                       { 44, 25 },
                       { 48, 25 },
                       { 52, 25 },
                       { 56, 25 },
                       { 60, 25 }},
          w[6][2]   = {{ 30, 15 },
                       { 33, 15 },
                       { 36, 17 },
                       { 39, 18 },
                       { 42, 20 },
                       { 45, 20 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jIS(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 1850, 1000 },
                       { 2800, 1800 },
                       { 2900, 1800 },
                       { 3100, 2000 },
                       { 4300, 2200 },
                       { 5800, 4700 }},
          m[6][2] =   {{ 1500, 1000 },
                       { 2500, 1800 },
                       { 2600, 1800 },
                       { 2700, 2000 },
                       { 3700, 2800 },
                       { 4900, 4000 }},
          w_s[6][2] = {{ 1700, 1000 },
                       { 1750, 1000 },
                       { 2200, 1400 },
                       { 2400, 1500 },
                       { 2700, 1900 },
                       { 2800, 1950 }},
          w[6][2]   = {{ 1400, 1000 },
                       { 1500, 1000 },
                       { 1900, 1300 },
                       { 2000, 1300 },
                       { 2200, 1500 },
                       { 2500, 1700 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jIG(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 0.65, 0.5 },
                       { 0.65, 0.5 },
                       { 0.65, 0.5 },
                       { 0.7, 0.5 },
                       { 0.7, 0.5 },
                       { 0.75, 0.5 }},
          m[6][2] =   {{ 0.55, 0.45 },
                       { 0.55, 0.45 },
                       { 0.55, 0.45 },
                       { 0.6, 0.45 },
                       { 0.6, 0.45 },
                       { 0.65, 0.45 }},
          w_s[6][2] = {{ 0.6, 0.5 },
                       { 0.6, 0.5 },
                       { 0.6, 0.5 },
                       { 0.65, 0.5 },
                       { 0.65, 0.5 },
                       { 0.7, 0.55 }},
          w[6][2]   = {{ 0.55, 0.5 },
                       { 0.55, 0.5 },
                       { 0.55, 0.5 },
                       { 0.6, 0.5 },
                       { 0.6, 0.5 },
                       { 0.65, 0.5 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jGEL(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 3000, 1500 },
                       { 3500, 1500 },
                       { 4000, 2000 },
                       { 4500, 2000 },
                       { 5000, 2500 },
                       { 5500, 2500 }},
          m[6][2] =   {{ 3000, 1500 },
                       { 3500, 2000 },
                       { 3500, 1500 },
                       { 4000, 2000 },
                       { 4500, 2000 },
                       { 5000, 2500 }},
          w_s[6][2] = {{ 2900, 1500 },
                       { 3400, 1500 },
                       { 3800, 2000 },
                       { 4200, 2000 },
                       { 4800, 2500 },
                       { 5200, 2500 }},
          w[6][2]   = {{ 2900, 1500 },
                       { 3300, 2000 },
                       { 3400, 1500 },
                       { 3600, 2000 },
                       { 4000, 2000 },
                       { 4500, 2500 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}


float SHVSMIntegralCreateDialog::jKEK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 3800, 2000 },
                       { 3800, 2000 },
                       { 3800, 2000 },
                       { 3700, 2200 },
                       { 3700, 2200 },
                       { 3600, 2400 }},
          m[6][2] =   {{ 4000, 2000 },
                       { 4000, 2000 },
                       { 4000, 2000 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4400, 2600 }},
          w_s[6][2] = {{ 4200, 2200 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4000, 2400 },
                       { 4000, 2400 },
                       { 3800, 2400 }},
          w[6][2]   = {{ 4000, 2000 },
                       { 4000, 2000 },
                       { 4000, 2000 },
                       { 4200, 2200 },
                       { 4200, 2200 },
                       { 4600, 2600 }},
          (*arr)[2];


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
    return 100.0*((arr[index][0] - val)/arr[index][1] - 1.0);
}

float SHVSMIntegralCreateDialog::jOPSS(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 2400, 2000 },
                       { 2400, 2000 },
                       { 2400, 2000 },
                       { 2600, 2200 },
                       { 2600, 2200 },
                       { 2800, 2400 }},
          m[6][2] =   {{ 2600, 2000 },
                       { 2600, 2000 },
                       { 2600, 2000 },
                       { 2600, 2200 },
                       { 2600, 2200 },
                       { 2800, 2400 }},
          w_s[6][2] = {{ 2500, 2000 },
                       { 2500, 2000 },
                       { 2500, 2000 },
                       { 2600, 2000 },
                       { 2600, 2000 },
                       { 2900, 2500 }},
          w[6][2]   = {{ 2800, 2000 },
                       { 2800, 2000 },
                       { 2800, 2000 },
                       { 2900, 2000 },
                       { 2900, 2000 },
                       { 2900, 2500 }},
          (*arr)[2];


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
    return 100.0*((arr[index][0] - val)/arr[index][1] - 1.0);
}

float SHVSMIntegralCreateDialog::jVC(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 520, 200 },
                       { 570, 200 },
                       { 640, 200 },
                       { 710, 200 },
                       { 800, 220 },
                       { 880, 240 }},
          m[6][2] =   {{ 500, 200 },
                       { 550, 200 },
                       { 620, 210 },
                       { 680, 210 },
                       { 740, 210 },
                       { 750, 220 }},
          w_s[6][2] = {{ 540, 200 },
                       { 600, 200 },
                       { 650, 200 },
                       { 700, 200 },
                       { 730, 210 },
                       { 780, 210 }},
          w[6][2]   = {{ 520, 200 },
                       { 580, 200 },
                       { 620, 200 },
                       { 660, 200 },
                       { 710, 220 },
                       { 730, 220 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jMOK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 3.5, 2.0 },
                       { 4.0, 2.5 },
                       { 4.5, 2.5 },
                       { 5, 2.5 },
                       { 5.5, 2.5 },
                       { 6, 3 }},
          m[6][2] =   {{ 3.5, 2 },
                       { 4, 2.5 },
                       { 4, 2 },
                       { 4.5, 2.5 },
                       { 5, 2.5 },
                       { 5.5, 3 }},
          w_s[6][2] = {{ 3.5, 2.0 },
                       { 3.5, 2.0 },
                       { 4, 2 },
                       { 4.5, 2 },
                       { 5, 2.5 },
                       { 5.5, 2.5 }},
          w[6][2]   = {{ 3.5, 2 },
                       { 3.5, 2 },
                       { 4, 2.5 },
                       { 4, 2.5 },
                       { 4.5, 2.5 },
                       { 5, 3 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}

float SHVSMIntegralCreateDialog::jSOK(float val)
{
    int index = (old < 12) ? 0 : old - 12;
    float m_s[6][2] = {{ 50, 20 },
                       { 50, 20 },
                       { 55, 25 },
                       { 65, 35 },
                       { 75, 40 },
                       { 85, 40 }},
          m[6][2] =   {{ 45, 25 },
                       { 45, 25 },
                       { 50, 25 },
                       { 55, 25 },
                       { 60, 25 },
                       { 75, 40 }},
          w_s[6][2] = {{ 50, 20 },
                       { 50, 20 },
                       { 55, 25 },
                       { 60, 25 },
                       { 65, 30 },
                       { 70, 35 }},
          w[6][2]   = {{ 45, 25 },
                       { 45, 25 },
                       { 50, 25 },
                       { 55, 25 },
                       { 60, 30 },
                       { 65, 35 }},
          (*arr)[2];


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
    return 100.0*(1.0 - (arr[index][0] - val)/arr[index][1]);
}


void SHVSMIntegralCreateDialog::juniorIS(float val)
{
    float m_s[4][6] = {{ 920, 1320, 1380, 1390, 1440, 1500 },
                       { 1119, 1629, 1679, 1779, 1819, 1939 },
                       { 1520, 2270, 2330, 2600, 3350, 4080 },
                       { 1720, 2600, 2650, 2950, 4110, 5280 }},
          m[4][6]   = {{ 770, 1100, 1150, 1160, 1200, 1250 },
                       { 935, 1359, 1410, 1480, 1515, 1620 },
                       { 1265, 1890, 1940, 2130, 2790, 3400 },
                       { 1720, 2600, 2650, 2950, 4110, 5280 }},
          w_s[4][6] = {{ 680, 925, 1000, 1000, 1080, 1080 },
                       { 819, 1099, 1199, 1319, 1379, 1439 },
                       { 1300, 1470, 1800, 1900, 2050, 2050 },
                       { 1540, 1650, 2100, 2220, 2400, 2460 }},
          w[4][6] =   {{ 570, 770, 865, 865, 900, 900 },
                       { 680, 925, 1010, 1100, 1150, 1200 },
                       { 1080, 1225, 1500, 1590, 1700, 1700 },
                       { 1280, 1380, 1745, 1850, 2000, 2050 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV11,ui->labelT11,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void SHVSMIntegralCreateDialog::juniorIG(float val)
{
    float m_s[4][6] = {{ 0.209, 0.209, 0.288, 0.288, 0.317 },
                       { 0.209, 0.209, 0.335, 0.335, 0.389 },
                       { 0.508, 0.508, 0.570, 0.570, 0.576 },
                       { 0.568, 0.568, 0.630, 0.630, 0.632 }},
          m[4][6]   = {{ 0.160, 0.160, 0.240, 0.240, 0.264 },
                       { 0.169, 0.169, 0.279, 0.279, 0.324 },
                       { 0.423, 0.423, 0.475, 0.475, 0.480 },
                       { 0.473, 0.473, 0.525, 0.525, 0.552 }},
          w_s[4][6] = {{ 0.139, 0.139, 0.179, 0.179, 0.239 },
                       { 0.189, 0.189, 0.233, 0.233, 0.239 },
                       { 0.469, 0.469, 0.492, 0.492, 0.508 },
                       { 0.520, 0.520, 0.552, 0.552, 0.568 }},
          w[4][6] =   {{ 0.116, 0.116, 0.149, 0.149, 0.150 },
                       { 0.157, 0.157, 0.194, 0.194, 0.199 },
                       { 0.391, 0.391, 0.410, 0.410, 0.423 },
                       { 0.433, 0.433, 0.460, 0.460, 0.473 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV10,ui->labelT10,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void SHVSMIntegralCreateDialog::juniorKEK(float val)
{
    float m_s[4][6] = {{ 65, 65, 65, 65, 65, 65 },
                       { 71, 74, 74, 75, 75, 75 },
                       { 95, 103, 103, 102, 102, 102 },
                       { 102, 112, 111, 111, 111, 111 }},
          m[4][6]   = {{ 70, 70, 70, 70, 70, 70 },
                       { 76, 79, 79, 80, 80, 80 },
                       { 100, 108, 108, 107, 107, 107 },
                       { 107, 117, 116, 115, 114, 114 }},
          w_s[4][6] = {{ 70, 70, 70, 70, 70, 70 },
                       { 75, 78, 78, 78, 79, 79 },
                       { 99, 107, 107, 106, 106, 106 },
                       { 116, 116, 115, 115, 115, 115 }},
          w[4][6] =   {{ 75, 75, 75, 75, 75, 75 },
                       { 79, 86, 89, 89, 89, 89 },
                       { 109, 109, 109, 104, 104, 104 },
                       { 124, 124, 118, 116, 116, 116 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV7,ui->labelT7,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}


void SHVSMIntegralCreateDialog::juniorIR(float val)
{
    float m_s[4][6] = {{ 65, 65, 65, 65, 65, 65 },
                       { 71, 74, 74, 75, 75, 75 },
                       { 95, 103, 103, 102, 102, 102 },
                       { 102, 112, 111, 111, 111, 111 }},
          m[4][6]   = {{ 70, 70, 70, 70, 70, 70 },
                       { 76, 79, 79, 80, 80, 80 },
                       { 100, 108, 108, 107, 107, 107 },
                       { 107, 117, 116, 115, 114, 114 }},
          w_s[4][6] = {{ 70, 70, 70, 70, 70, 70 },
                       { 75, 78, 78, 78, 79, 79 },
                       { 99, 107, 107, 106, 106, 106 },
                       { 116, 116, 115, 115, 115, 115 }},
          w[4][6] =   {{ 75, 75, 75, 75, 75, 75 },
                       { 79, 86, 89, 89, 89, 89 },
                       { 109, 109, 109, 104, 104, 104 },
                       { 124, 124, 118, 116, 116, 116 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV6,ui->labelT6,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void SHVSMIntegralCreateDialog::juniorSOK(float val)
{
    float m_s[4][6] = {{ 36, 40.5, 44.5, 48, 51.5, 54 },
                      { 38.4, 41.9, 46.4, 50.4, 53.9, 57.4 },
                      { 42, 45.5, 49, 53, 56.5, 72 },
                      { 44.5, 48, 51.5, 54.5, 59, 75.5 }},
          m[4][6]   = {{ 30, 34, 37, 40, 43, 45 },
                      { 31.9, 35.9, 38.9, 43.9, 44.9, 47.9 },
                      { 35, 38, 41, 44, 47, 60 },
                      { 37, 40, 43, 46, 49, 63}},
          w_s[4][6] = {{ 36, 37.5, 41, 44, 46.5, 48 },
                      { 38.4, 38.9, 42.9, 46.4, 48.9, 51.4 },
                      { 42, 42.5, 45.5, 49, 51.5, 66 },
                      { 44.5, 45, 48, 50.5, 53, 69.5 }},
          w[4][6] =   {{ 30, 32, 35.5, 37, 39.5, 41 },
                      { 31.9, 33.9, 36.4, 40.9, 41.4, 43.9 },
                      { 35, 36, 38.5, 41, 43.5, 56 },
                      { 37, 38, 40.5, 43, 45.5, 59 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV1,ui->labelT1,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void SHVSMIntegralCreateDialog::juniorMOK(float val)
{
    float m_s[4][6] = {{ 2.5, 2.8, 3.1, 3.4, 3.7, 4.19 },
                       { 2.69, 2.99, 3.29, 3.59, 3.89, 4.19 },
                       { 2.9, 3.2, 3.5, 3.8, 4.1, 5.2 },
                       { 3.1, 3.4, 3.7, 4.0, 4.3, 5.4 }},
          m[4][6]   = {{ 2.4, 2.6, 2.8, 3.0, 3.2, 3.4 },
                       { 2.59, 2.79, 2.99, 3.19, 3.39, 3.59 },
                       { 2.8, 3.0, 3.2, 3.4, 3.6, 4.6 },
                       { 3.0, 3.2, 3.4, 3.6, 3.8, 4.8 }},
          w_s[4][6] = {{ 2.5, 2.7, 2.9, 3.1, 3.3, 3.4 },
                       { 2.69, 2.89, 3.09, 3.29, 3.49, 3.69 },
                       { 2.9, 3.1, 3.3, 3.5, 3.7, 4.7 },
                       { 3.1, 3.3, 3.5, 3.7, 3.9, 4.9 }},
          w[4][6] =   {{ 2.4, 2.5, 2.6, 2.7, 2.8, 2.9 },
                       { 2.59, 2.69, 2.79, 2.89, 2.99, 3.09 },
                       { 2.8, 2.9, 3.0, 3.1, 3.2, 4.1 },
                       { 3.0, 3.1, 3.2, 3.3, 3.4, 4.3 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV2,ui->labelT2,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}


void SHVSMIntegralCreateDialog::juniorOPSS(float val)
{
    float m_s[4][6] = {{ 600, 600, 700, 700, 800, 800 },
                       { 999, 999, 1099, 1099, 1119, 1119 },
                       { 1800, 1800, 1900, 1900, 2000, 2000 },
                       { 2200, 2200, 2300, 2300, 2400, 2400 }},
          m[4][6]   = {{ 800, 800, 900, 900, 1000, 1000 },
                       { 1199, 1199, 1299, 1299, 1319, 1319 },
                       { 2400, 2400, 2500, 2500, 2600, 2600 },
                       { 2400, 2400, 2500, 2500, 2600, 2600 }},
          w_s[4][6] = {{ 700, 700, 800, 800, 900, 900 },
                       { 1099, 1099, 1199, 1199, 1219, 1219 },
                       { 1900, 1900, 2000, 2000, 2100, 2100 },
                       { 2300, 2300, 2400, 2400, 2500, 2500 }},
          w[4][6] =   {{ 1000, 1000, 1100, 1100, 1200, 1200 },
                       { 1399, 1399, 1499, 1499, 1599, 1599 },
                       { 2200, 2200, 2300, 2300, 2400, 2400 },
                       { 2600, 2600, 2700, 2700, 2800, 2800 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV4,ui->labelT4,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void SHVSMIntegralCreateDialog::juniorVC(float val)
{
    float m_s[4][6] = {{ 360, 420, 470, 550, 600, 680 },
                       { 389, 449, 509, 579, 639, 719 },
                       { 450, 510, 570, 640, 720, 800 },
                       { 480, 540, 600, 670, 760, 840 }},
          m[4][6]   = {{ 340, 400, 460, 510, 580, 640 },
                       { 369, 429, 489, 549, 609, 669 },
                       { 430, 490, 550, 610, 670, 730 },
                       { 460, 520, 580, 640, 700, 760 }},
          w_s[4][6] = {{ 390, 450, 515, 570, 610, 645 },
                       { 419, 479, 439, 589, 629, 669 },
                       { 480, 540, 590, 630, 670, 720 },
                       { 510, 570, 616, 650, 690, 745 }},
          w[4][6] =   {{ 370, 430, 490, 500, 530, 550 },
                       { 399, 459, 519, 529, 559, 579 },
                       { 460, 520, 580, 590, 620, 640 },
                       { 490, 550, 610, 620, 650, 670 }},
          (*arr)[6];

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

    if (old <= 12)
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][0],arr[1][0],arr[2][0],arr[3][0]);
    else if (old > 12 && old <= 13)
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][1],arr[1][1],arr[2][1],arr[3][1]);
    else if (old > 13 && old <= 14)
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][2],arr[1][2],arr[2][2],arr[3][2]);
    else if (old > 14 && old <= 15)
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][3],arr[1][3],arr[2][3],arr[3][3]);
    else if (old > 16 && old <= 17)
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][4],arr[1][4],arr[2][4],arr[3][4]);
    else
        showIndicatorTxt(ui->labelV5,ui->labelT5,val,arr[0][5],arr[1][5],arr[2][5],arr[3][5]);
}

void normalize(float& p)
{
    if (p < 0)
        p = 0;
    else if (p > 100)
        p = 100;
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
    model->setHeaderData(4, Qt::Horizontal, tr("Qualification"));
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
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV1,ui->labelT1,sok,50.00,59.99,80.00,90.00);
            else
                showIndicatorTxt(ui->labelV1,ui->labelT1,sok,45.00,54.99,75.00,85.00);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV1,ui->labelT1,sok,40.00,44.99,70.00,80.00);
            else
                showIndicatorTxt(ui->labelV1,ui->labelT1,sok,39.50,48.49,66.50,75.50);
        }
    }
    else
        juniorSOK(sok);
    // ------------------------------ 2. МОК ----------------------------------------
    mok = hr*sok/1000.0;
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV2,ui->labelT2,mok,4.50,5.49,7.50,8.50);
            else
                showIndicatorTxt(ui->labelV2,ui->labelT2,mok,3.50,4.49,6.50,7.50);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV2,ui->labelT2,mok,3.00,3.99,6.00,7.00);
            else
                showIndicatorTxt(ui->labelV2,ui->labelT2,mok,2.50,3.49,5.50,6.50);
        }
    }
    else
        juniorMOK(mok);
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
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV4,ui->labelT4,opss,800.00,1199.00,2000.00,2400.00);
            else
                showIndicatorTxt(ui->labelV4,ui->labelT4,opss,900.00,1299.00,2100.00,2500.00);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV4,ui->labelT4,opss,1000.00,1399.00,2200.00,2600.00);
            else
                showIndicatorTxt(ui->labelV4,ui->labelT4,opss,1200.00,1599.00,2400.00,2800.00);
        }
    }
    else
        juniorOPSS(opss);
    // ------------------------------ 5. VC ----------------------------------------
    vc = 40.0*pow(1000.0*weight/growth,0.5);
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV5,ui->labelT5,vc,825.00,879.00,990.00,1045.00);
            else
                showIndicatorTxt(ui->labelV5,ui->labelT5,vc,720.00,759.00,840.00,880.00);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV5,ui->labelT5,vc,680.00,719.00,800.00,840.00);
            else
                showIndicatorTxt(ui->labelV5,ui->labelT5,vc,500.00,539.00,620.00,660.00);
        }
    }
    else
        juniorVC(vc);

    // ------------------------------ 6. ИР ----------------------------------------
    ir = hr*sbp/100;
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,98.00,93.00,66.00,56.00);
            else
                showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,103.00,98.00,71.00,61.00);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,108.00,103.00,76.00,66.00);
            else
                showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,110.00,105.00,78.00,68.00);
        }
    }
    else
        juniorIR(ir);
    // ------------------------------ 7. КЭК ----------------------------------------
    kek = hr*(sbp - dbp);
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3200.00,2801.00,2000.00,1600.00);
            else
                showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3400.00,3001.00,2200.00,1800.00);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3600.00,3201.00,2400.00,2900.00);
            else
                showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3800.00,3401.00,2600.00,2200.00);
        }
    }
    else
        juniorKEK(kek);
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

        ui->labelV9->setText(QString("%1").arg(oadc,0,'f',2));
        if (oadc < 0)
            ui->labelT9->setText(tr("Below the norm"));
        else if (oadc >=0 && oadc <= 30)
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

        ui->labelV9->setText(QString("%1").arg(oadc,0,'f',2));
        if (oadc < 0)
            ui->labelT9->setText(tr("Below the norm"));
        else if (oadc >=0 && oadc <= 20)
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
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.52,0.609,0.787,0.884);
            else
                showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.42,0.509,0.687,0.774);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.32,0.409,0.587,0.674);
            else
                showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.26,0.369,0.547,0.634);
        }
    }
    else
        juniorIG(ig);


    // ------------------------------ 11. ИC ----------------------------------------
    is = 2.0*dgel*dtbe/hr;
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV11,ui->labelT11,is,2800,3500,4901,5600);
            else
                showIndicatorTxt(ui->labelV11,ui->labelT11,is,2300,3000,4401,5100);
        }
        else
        {
            if (sex == 1)
                showIndicatorTxt(ui->labelV11,ui->labelT11,is,1800,2500,3901,4600);
            else
                showIndicatorTxt(ui->labelV11,ui->labelT11,is,800,1500,2901,3600);
        }
    }
    else
        juniorIS(is);

    // ------------------------------ 12. УФСС ----------------------------------------
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                p_sok = 100.0*(1.0 - (100.0 - sok)/60.0);
                p_mok = 100.0*(1.0 - (10.0 - mok)/7.0);
                p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
                p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
                p_vc = 100.0*(1.0 - (1200.0 - vc)/700.0);
                p_opss = 100.0*((2800.0 - opss)/2400.0 - 1.0);
                p_ir = 100.0*((120.0 - ir)/80.0 - 1.0);
                p_kek = 100.0*((3600.0 - kek)/2400.0 - 1.0);
                p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
            }
            else
            {
                p_sok = 100.0*(1.0 - (90.0 - sok)/55.0);
                p_mok = 100.0*(1.0 - (8.0 - mok)/5.0);
                p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
                p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
                p_vc = 100.0*(1.0 - (1000.0 - vc)/700.0);
                p_opss = 100.0*((2900.0 - opss)/2500.0 - 1.0);
                p_ir = 100.0*((125.0 - ir)/80.0 - 1.0);
                p_kek = 100.0*((3800.0 - kek)/2400.0 - 1.0);
                p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
            }
        }
        else
        {
            if (sex == 1)
            {
                p_sok = 100.0*(1.0 - (90.0 - sok)/60.0);
                p_mok = 100.0*(1.0 - (9.0 - mok)/7.0);
                p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
                p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
                p_vc = 100.0*(1.0 - (900.0 - vc)/600.0);
                p_opss = 100.0*((3000.0 - opss)/2400.0 - 1.0);
                p_ir = 100.0*((130.0 - ir)/85.0 - 1.0);
                p_kek = 100.0*((4400.0 - kek)/2600.0 - 1.0);
                p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
            }
            else
            {
                p_sok = 100.0*(1.0 - (85.0 - sok)/55.0);
                p_mok = 100.0*(1.0 - (7.0 - mok)/5.0);
                p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
                p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
                p_vc = 100.0*(1.0 - (800.0 - vc)/650.0);
                p_opss = 100.0*((3200.0 - opss)/2400.0 - 1.0);
                p_ir = 100.0*((135.0 - ir)/80.0 - 1.0);
                p_kek = 100.0*((4600.0 - kek)/2600.0 - 1.0);
                p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
            }
        }
    }
    else
    {
        p_sok = jSOK(sok);
        p_mok = jMOK(mok);
        p_oadc = 100.0*((20.0 - oadc)/20.0 - 1.0);
        p_oadd = 100.0*((20.0 - oadd)/20.0 - 1.0);
        p_vc = jVC(vc);
        p_opss = jOPSS(opss);
        if (sex == 1)
            p_ir = 100.0*((130.0 - ir)/80.0 - 1.0);
        else
            p_ir = 100.0*((130.0 - ir)/90.0 - 1.0);
        p_kek = jKEK(kek);
        p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
    }

    normalize(p_sok);
    normalize(p_mok);
    normalize(p_oadc);
    normalize(p_oadd);
    normalize(p_vc);
    normalize(p_opss);
    normalize(p_ir);
    normalize(p_kek);
    normalize(p_si);

    ufss = (p_sok + p_mok + p_oadc + p_oadd + p_vc + p_opss + p_ir + p_kek + p_si)/9.0;
    showIndicatorTxt(ui->labelV12,ui->labelT12,ufss,33.0,49.6,66.1,82.6);
    // ------------------------------ 13. УФСВД ----------------------------------------
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                p_dgel = 100.0*(1.0 - (5500.0 - dgel)/3500.0);
                p_ig = 100.0*(1.0 - (0.95 - ig)/0.55);
                p_is = 100.0*(1.0 - (6000.0 - is)/3600.0);
                p_dte = 100.0*(1.0 - (100.0 - dte)/70.0);
                p_dtbe = 100.0*(1.0 - (80.0 - dtbe)/50.0);
                p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
            }
            else
            {
                p_dgel = 100.0*(1.0 - (5000.0 - dgel)/3000.0);
                p_ig = 100.0*(1.0 - (0.85 - ig)/0.5);
                p_is = 100.0*(1.0 - (5500.0 - is)/3100.0);
                p_dte = 100.0*(1.0 - (90.0 - dte)/60.0);
                p_dtbe = 100.0*(1.0 - (70.0 - dtbe)/40.0);
                p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
            }
        }
        else
        {
            if (sex == 1)
            {
                p_dgel = 100.0*(1.0 - (5000.0 - dgel)/3000.0);
                p_ig = 100.0*(1.0 - (0.725 - ig)/0.41);
                p_is = 100.0*(1.0 - (5400.0 - is)/4600.0);
                p_dte = 100.0*(1.0 - (85.0 - dte)/65.0);
                p_dtbe = 100.0*(1.0 - (65.0 - dtbe)/50.0);
                p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
            }
            else
            {
                p_dgel = 100.0*(1.0 - (4000.0 - dgel)/2500.0);
                p_ig = 100.0*(1.0 - (0.684 - ig)/0.44);
                p_is = 100.0*(1.0 - (4400.0 - is)/3800.0);
                p_dte = 100.0*(1.0 - (75.0 - dte)/60.0);
                p_dtbe = 100.0*(1.0 - (55.0 - dtbe)/40.0);
                p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
            }
        }
    }
    else
    {
        p_dgel = jGEL(dgel);
        p_ig = jIG(ig);
        p_is = jIS(is);
        p_dte = jDTE(dte);
        p_dtbe = jDTBE(dte);
        p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
    }
    normalize(p_dgel);
    normalize(p_ig);
    normalize(p_is);
    normalize(p_dte);
    normalize(p_dtbe);
    normalize(p_dev_dgel);

    ufsvd = (p_dgel + p_ig + p_is + p_dte + p_dtbe + p_dev_dgel)/6.0;
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
                                 V6=%18,V7=%19,V8=%20,V9=%21,V10=%22,V11=%23,V12=%24,V13=%25,old=%26,I1=%27,I2=%28,I4=%29,I5=%30,I6=%31,I7=%32,I10=%33,I11=%34 \
                                 WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                                arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel).arg(dev_dgel).arg(dte).arg(dtbe).arg(sok).arg(mok).arg(si).arg(opss).arg(vc).arg(ir).arg(kek).arg(oadc).\
                                arg(oadd).arg(ig).arg(is).arg(ufss).arg(ufsvd).arg(old).arg(p_sok).arg(p_mok).arg(p_opss).arg(p_vc).arg(p_ir).arg(p_kek).arg(p_ig).arg(p_is)))
            QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

        return;
    }


    if (!query.exec(QString("INSERT INTO surveySHVSMIntegral (surveyed_id,dt,weight,growth,HR,SAD,DAD,VL,VLN,VLD,T1,T2,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13,old) \
                             VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%26)").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                             arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel).arg(dev_dgel).arg(dte).arg(dtbe).arg(sok).arg(mok).arg(si).arg(opss).arg(vc).arg(ir).arg(kek).arg(oadc).\
                             arg(oadd).arg(ig).arg(is).arg(ufss).arg(ufsvd).arg(old)))
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
    text += tr("<tr><th width=\"200%\">Surname</th><th>Sex</th><th>Age</th><th>Qualification</th><th>Body<br>length (sm)</th><th>Body<br>mass (kg)</th></tr>");
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
    text += tr("<tr><td colspan=\"4\"Systolic arterial pressure deviation</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV8->text().toFloat(),0,'f',2).arg(ui->labelT8->text());
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

