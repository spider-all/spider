#include <iostream>
#include <random>

#include <leveldb/db.h>
#include <leveldb/write_batch.h>
#include <spdlog/spdlog.h>

#include <error.h>

#include <database/database.h>

#pragma once

class Level : public Database {
private:
  leveldb::Status status;

public:
  explicit Level(const std::string &);
  ~Level() override;
  int initialize() override;

  int64_t count_x(const std::string &table, const std::string &field);

  int create_user(User) override;
  int64_t count_user() override;
  std::vector<std::string> list_users() override;
  std::vector<User> list_usersx(common_args args) override;

  int create_org(Org) override;
  int64_t count_org() override;
  std::vector<std::string> list_orgs() override;

  int create_emoji(std::vector<Emoji> emojis) override;
  int64_t count_emoji() override;

  int create_gitignore(Gitignore gitignore) override;
  int64_t count_gitignore() override;

  int create_license(License license) override;
  int64_t count_license() override;
};
