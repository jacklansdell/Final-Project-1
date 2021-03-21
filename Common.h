#pragma once
class Common
{
public:
    virtual std::vector <Worker*> getAvailWorkers() = 0;
    virtual std::vector <Good*> getSoldableGoods() = 0;
};

