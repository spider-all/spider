#include <cassert>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <SQLiteCpp/SQLiteCpp.h>
#include <spdlog/spdlog.h>

#pragma once

#include <database/database.h>
#include <error.hpp>
#include <model.h>

class SQLite3 : public Database {
public:
  explicit SQLite3(const std::string &);
  ~SQLite3() override;
  int initialize() override;
  int create_user(User) override;
  std::vector<std::string> list_users() override;
  int64_t count_user() override;

  int create_org(Org) override;
  int64_t count_org() override;
  std::vector<std::string> list_orgs() override;

  int create_emoji(std::vector<Emoji> emojis) override;
  int64_t count_emoji() override;
};
