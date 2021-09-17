#include <config.h>

int Config::initialize(const std::string &config_path) {
  YAML::Node config = YAML::LoadFile(config_path);
  crawler_entry_username = config["entry"].as<std::string>();
  crawler_token = config["token"].as<std::vector<std::string>>();
  crawler_useragent = config["useragent"].as<std::string>();
  crawler_timezone = config["timezone"].as<std::string>();
  crawler_sleep_each_request = config["sleep"].as<int64_t>();

  database_type = config["database"]["type"].as<std::string>();
  if (database_type == DATABASE_SQLTE3) {
    database_sqlite3_path = config["database"][DATABASE_SQLTE3]["path"].as<std::string>();
  } else if (database_type == DATABASE_LEVELDB) {
    database_leveldb_path = config["database"][DATABASE_LEVELDB]["path"].as<std::string>();
  } else if (database_type == DATABASE_MONGODB) {
    database_mongodb_dsn = config["database"][DATABASE_MONGODB]["dsn"].as<std::string>();
  } else if (database_type == DATABASE_MYSQL) {
    database_mysql_host = config["database"][DATABASE_MYSQL]["host"].as<std::string>();
    database_mysql_user = config["database"][DATABASE_MYSQL]["user"].as<std::string>();
    database_mysql_password = config["database"][DATABASE_MYSQL]["password"].as<std::string>();
    database_mysql_db = config["database"][DATABASE_MYSQL]["db"].as<std::string>();
    database_mysql_port = config["database"][DATABASE_MYSQL]["port"].as<unsigned int>();
  } else if (database_type == DATABASE_POSTGRESQL) {
    database_mongodb_dsn = config["database"][DATABASE_POSTGRESQL]["dsn"].as<std::string>();
  }

  if (crawler_entry_username.empty() || crawler_token.empty()) {
    spdlog::error("Config {0} have not the import value.", config_path);
    return CONFIG_PARSE_ERROR;
  }

  return 0;
}
