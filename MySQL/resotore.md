# Reset mysql root password
sudo /etc/init.d/mysql stop
mysqld_safe --skip-grant-tables &


root ps: 

# How to restore Database using ibd frm files and data files

sudo apt install mysql-utilities

mysqlfrm --diagnostic

mysqlfrm --server=root:g0ah5dyr0!n0w@localhost:3306 "zone.frm" > zone.txt --port=3310


    sudo mysqlfrm --server=root:''@127.0.0.1:3306 "hungrynaki_v2_5.zone.frm" > zone.txt --port=3310
 
https://dev.mysql.com/doc/refman/5.6/en/innodb-migration.html

https://recovery.twindb.com/



Where does the created MySQL database folder stored in OSX?

SELECT @@datadir, @@innodb_data_home_dir



 ALTER TABLE zone DISCARD TABLESPACE;

 ALTER TABLE zone IMPORT TABLESPACE;

 

  ALTER TABLE reguler_order DISCARD TABLESPACE;

 ALTER TABLE reguler_order IMPORT TABLESPACE;



CREATE TABLE `zone` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(300) NOT NULL,
  `city_id` int(11) NOT NULL,
  `code` varchar(10) NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  `status` int(11) DEFAULT '0',
  `updated_by` int(11) DEFAULT '1',
  `status_updated_date` datetime NOT NULL,
  `status_updated_email` varchar(200) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_city_zone` (`city_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;