#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type);

    const std::string&  getType( void );
    void                setType( const std::string& newType );
};

#endif