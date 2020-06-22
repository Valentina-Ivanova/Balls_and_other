void Building::load(ifstream& stream) {
    ///stream >> tmp >> buff;
    ///stream >> tmp >> buff;
    stream >> tmp >> m_width;
    stream >> tmp >> m_height;
    stream >> tmp >> m_health;
    stream >> tmp >> m_capacity;
    stream >> tmp >> m_states;
    stream >> tmp >> m_maxState;
    stream >> tmp >> m_moralImpact;
    stream >> tmp >> m_healthImpact;
    stream >> tmp >> m_damageImpact;
    stream >> tmp >> m_effectPeriod;
    stream >> tmp >> m_moralImpactEffect;
    stream >> tmp >> m_healthImpactEffect;
    stream >> tmp >> m_damageImpactEffect;

    return;
}



void Building::load(string configFile, SDL_Renderer* renderer)
{
    configFile = "config\" + configFile;
    ifstream stream;
    string tmp, buff;

    stream.open(configFile.c_str());

    Tile::load(stream);
    load(stream);


    stream.close();

    m_healthPerState = m_health / m_states;
    m_drawState.w = m_width;
    m_drawState.h = m_height;
}
