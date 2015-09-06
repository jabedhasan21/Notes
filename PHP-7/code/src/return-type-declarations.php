<?php
class User{}

function getUser() : User{
  return new User;
  //return [];
}

var_dump(getUser());
