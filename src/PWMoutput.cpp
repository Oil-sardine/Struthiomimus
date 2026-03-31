#include "Arduino.h"
//torque 参照バージョン

// モータパラメータ
const float Kt = 49.0/3.0f;      // トルク定数 [Nm/A]
const float Ke = 12.0/111.7f;      // 逆起電力定数 [V/(rad/s)]
const float R  = 1.0f;      // 抵抗 [Ω] [未定]
const float V_supply = 12.0f; // 電源電圧 [V]

// PWM設定
const int MF_1 = 32;
const int MF_2 = 35;

const int ch1 = 0;
const int ch2 = 1;

void pwmsetup() {
    ledcSetup(ch1, 1000, 8); // 周波数1kHz, 8bit
    ledcSetup(ch2, 1000, 8);

    ledcAttachPin(MF_1, ch1);
    ledcAttachPin(MF_2, ch2);
}

void loop() {
  float torque_cmd = 0.2f;  // 指令トルク [Nm]　[変数化]
  float omega = 50.0f;      // 角速度 [rad/s][光学式ロータリーエンコーダーから]

  // ① トルク → 電流
  float current = torque_cmd / Kt;

  // ② 電流 → 電圧
  float voltage = R * current + Ke * omega;

  // ③ 電圧 → Duty
  float duty = voltage / V_supply;

  // 制限（安全対策）
  if (duty > 1.0f) duty = 1.0f;
  if (duty < 0.0f) duty = 0.0f;

  // PWM出力（0-255）
  int pwmValue = (int)(duty * 255);

  // モーターヘ送信
    if (pwmValue > 0) {
        ledcWrite(ch1, pwmValue);
        ledcWrite(ch2, 0);
    } else {
        ledcWrite(ch1, 0);
        ledcWrite(ch2, -pwmValue); // 符号反転
    }
    delay(10);
}