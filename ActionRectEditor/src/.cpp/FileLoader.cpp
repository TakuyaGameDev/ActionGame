#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <regex>
#include "../.h/FileLoader.h"
#include "../.h/Animation.h"

using namespace std::filesystem;
FileLoader* FileLoader::instance_ = nullptr;

const Vector2I& FileLoader::GetImageSize(std::string filename)
{
    // ‰æ‘œƒTƒCƒYŠi”[—p
    Vector2I tmpImageSize = { 0,0 };

    std::ifstream readingFile;

    readingFile.open("ImageData/Actors/"+ filename + "/ImageSize/data.txt", std::ios::in);
    std::string readingLineBuf;
    while (std::getline(readingFile,readingLineBuf,'='))
    {
        int strPos1 = readingLineBuf.find_first_of('{');
        int strPos2 = readingLineBuf.find_first_of('}');
        if (strPos1 != readingLineBuf.npos)
        {
            readingLineBuf.replace(strPos1, 1, "");
            readingLineBuf.replace(strPos2-1, 1, "");
            std::stringstream str(readingLineBuf);
            while (std::getline(str, readingLineBuf, ','))
            {
                if (readingLineBuf == "\n")
                {
                    break;
                }
                if (tmpImageSize.x == 0)
                {
                    tmpImageSize.x = std::atoi(readingLineBuf.c_str());
                }
                else if(tmpImageSize.y == 0)
                {
                    tmpImageSize.y = std::atoi(readingLineBuf.c_str());
                }
            }
        }
    }
    return tmpImageSize;
}

const Vector2I& FileLoader::LoadAnimationData(std::string filename)
{
    Vector2I tmpDivCnt;
    std::ifstream readingFile;
    readingFile.open("ImageData/Actors/"+lpAnimation.GetObjectName() + "/Animations/" + filename + ".txt", std::ios::in);
    std::string readingLineBuf;

    while (std::getline(readingFile, readingLineBuf, '\n'))
    {
        int strPos1 = readingLineBuf.find_first_of('{');
        int strPos2 = readingLineBuf.find_first_of('}');
        if (strPos1 != readingLineBuf.npos)
        {
            readingLineBuf.replace(strPos1, 1, "");
            readingLineBuf.replace(strPos2 - 1, 1, "");
            std::stringstream str(readingLineBuf);
            while (std::getline(str, readingLineBuf, '='))
            {
                if (readingLineBuf == "count")
                {
                    while (std::getline(str, readingLineBuf, ','))
                    {
                        if (tmpDivCnt.x == 0)
                        {
                            tmpDivCnt.x = std::atoi(readingLineBuf.c_str());
                        }
                        else if(tmpDivCnt.y == 0)
                        {
                            tmpDivCnt.y = std::atoi(readingLineBuf.c_str());
                        }
                    }
                }
                else if (readingLineBuf == "duration")
                {
                    while (std::getline(str, readingLineBuf, ','))
                    {
                        lpAnimation.SetDuration(std::stof(readingLineBuf));
                    }
                }
                else
                {
                    while (std::getline(str, readingLineBuf, ','))
                    {
                        lpAnimation.SetMaxFrame(std::atoi(readingLineBuf.c_str()));
                    }
                }
            }
        }
    }
    return tmpDivCnt;
}

void FileLoader::FindFileNameList(std::string path)
{
    directory_iterator itr("Images/Actors/"+path), end;
    std::error_code err;

    for (; itr != end && !err; itr.increment(err)) {
        const directory_entry entry = *itr;
        int strPos = entry.path().string().find("\\");
        auto tmpStr = entry.path().string().substr(strPos + 1);
        fileNames_.push_back(entry.path().string().replace(strPos,strPos+1,"/")+tmpStr);
    }
}

FileLoader::~FileLoader()
{
}
