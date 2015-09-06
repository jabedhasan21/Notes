<?php
class User {

  protected $name;
  protected $age;

  public function __construct($name,$age){
    $this->name = $name;
    $this->age = $age;
  }

  public function name() {
   return $this->name;
  }

  public function age() {
   return $this->age;
  }

}

class UserCollection {

  protected $users;

  public function __construct(array $users) {
      $this->users = $users;
  }

  public function users() {
    return $this->users;
  }
  public function sortBy($method) {
    usort($this->users, function($userOne, $userTwo) use($method){
        return $userOne->$method() <=> $userTwo->$method();
    });
  }

}


$collection = new UserCollection([
    new User('jabed',126),
    new User('bangali',36),
    new User('hasan',46),
    new User('babu',56),
    new User('md',66),
  ]);

  //$collection->sortBy('age');
  $collection->sortBy('name');
  var_dump($collection->users());
