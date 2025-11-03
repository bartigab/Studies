CREATE DATABASE IF NOT EXISTS `cards_db`
  CHARACTER SET utf8mb4
  COLLATE utf8mb4_unicode_ci;

USE `cards_db`;


CREATE TABLE IF NOT EXISTS `users` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(255) NOT NULL,
  `email` VARCHAR(255) NOT NULL,
  `password` VARCHAR(255) NOT NULL,
  `created_at` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_login` TIMESTAMP NULL DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `users_email_unique` (`email`)
);


CREATE TABLE IF NOT EXISTS `access_tokens` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_user` INT UNSIGNED NOT NULL,
  `token` VARCHAR(128) NOT NULL,
  `created` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `access_tokens_token_unique` (`token`),
  KEY `access_tokens_id_user_index` (`id_user`),
  CONSTRAINT `access_tokens_id_user_fk` FOREIGN KEY (`id_user`)
    REFERENCES `users` (`id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);


CREATE TABLE IF NOT EXISTS `cards` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `id_user` INT UNSIGNED NULL,
  `card_number` VARCHAR(20) NOT NULL,
  `pin` VARCHAR(8) NOT NULL,
  `activation` DATETIME NOT NULL,
  `expires_on` DATE NOT NULL,
  `balance` DECIMAL(10,2) NOT NULL DEFAULT 0.00,
  `created` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP,
  `updated` TIMESTAMP NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `cards_card_number_unique` (`card_number`),
  KEY `cards_id_user_index` (`id_user`),
  CONSTRAINT `cards_id_user_foreign` FOREIGN KEY (`id_user`)
    REFERENCES `users` (`id`)
    ON DELETE SET NULL
    ON UPDATE CASCADE
);
