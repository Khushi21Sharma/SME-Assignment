#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

class Bullet {
public:
    enum Type {
        Simple,
        FrostBeam,
        Torpedo,
        LockedMissile
    };

    Bullet(Type type, int x, int y) : type(type), posX(x), posY(y) {}

    void update() {
        // Update bullet position based on its speed and direction
        // ...
    }

private:
    Type type;
    int posX;
    int posY;
};

namespace Enemy {
    class EnemyModel {
        // Existing code for EnemyModel...

        virtual void fireBullet() = 0;
    };

    class SubZero : public EnemyModel {
        // Existing code for SubZero...

        void fireBullet() override {
            if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastFireTime).count() >= fireDelay) {
                bullets.push_back(Bullet(Bullet::FrostBeam, posX, posY));
                lastFireTime = std::chrono::steady_clock::now();
            }
        }

    private:
        std::vector<Bullet> bullets;
        std::chrono::steady_clock::time_point lastFireTime;
        int fireDelay = 1000; // Delay between each bullet in milliseconds
    };

    class ThunderSnake : public EnemyModel {
        // Existing code for ThunderSnake...

        void fireBullet() override {
            if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastFireTime).count() >= fireDelay) {
                bullets.push_back(Bullet(Bullet::Torpedo, posX, posY));
                lastFireTime = std::chrono::steady_clock::now();
            }
        }

    private:
        std::vector<Bullet> bullets;
        std::chrono::steady_clock::time_point lastFireTime;
        int fireDelay = 1500; // Delay between each bullet in milliseconds
    };

    class Zapper : public EnemyModel {
        // Existing code for Zapper...

        void fireBullet() override {
            if (std::chrono:duration_cast<std:chrono:milliseconds>(std:chrono:steady_clock:now() - lastFireTime).count() >= fireDelay) {
                bullets.push_back(Bullet(Bullet:LockedMissile, posX, posY));
                lastFireTime = std:chrono:steady_clock:now();
            }
        }

    private:
        std:vector<Bullet> bullets;
        std:chrono:steady_clock:time_point lastFireTime;
        int fireDelay = 2000; // Delay between each bullet in milliseconds
    };
}

namespace Player {
    class PlayerModel {
       // Existing code for PlayerModel...

        void fireBullet() {
            if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastFireTime).count() >= fireDelay) {
                bullets.push_back(Bullet(Bullet::Simple, posX, posY));
                lastFireTime = std::chrono::steady_clock::now();
            }
        }

    private:
        std::vector<Bullet> bullets;
        std::chrono::steady_clock::time_point lastFireTime;
        int fireDelay = 500; // Delay between each bullet in milliseconds
    };
}