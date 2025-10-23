<?php

class Uploadfile extends Datafile {

    public $error = "";
    public $prefix = "";
    public $image = "image";
    public $folder = "files/";

    public function insert($file) {
      $sufix = $this->GETSUFIX($file['type']);
      if ($sufix === false) {
          $this->error = "Nieprawidlowy typ pliku";
          return false;
      }

      $fileData = [
          "userid" => $_SESSION['user']['userid'],
          "postid" => $_POST["postid"],
          "topicid" => $_SESSION["topicid"],
          "name" => pathinfo($file['name'], PATHINFO_FILENAME),
          "sufix" => $sufix,
          "title" => !empty($_POST["imagetitle"]) ? $_POST["imagetitle"] : pathinfo($file['name'], PATHINFO_FILENAME),
          "date" => date("Y-m-d H:i:s")
      ];

      parent::insert($fileData);

      $img = parent::getLastItem();
      $filePath = $this->folder . $this->prefix . $img["id"] . $sufix;

      if (move_uploaded_file($file['tmp_name'], $filePath)) {
          return $img["id"];
      }

      parent::delete($img["id"]);
      $this->error = "Upload error!";
      return false;
  }

  public function update($id, $title = "") {
    $img = $this->get($id);
    $img["title"] = !empty($title) ? $title : $img["name"];
    return parent::update($img);
}

public function delete($id, $key = false) {
    if (!($img = $this->get($id))) {
        return false;
    }

    $filePath = $this->folder . $this->prefix . $img["id"] . $img["sufix"];
    if (file_exists($filePath) && unlink($filePath)) {
        return parent::delete($id);
    }

    return false;
}

public function frompost($postid) {
    $result = true;
    $imgs = $this->getAll($postid, "postid");

    if (!empty($imgs)) {
        foreach ($imgs as $k => $v) {
            $result &= $this->delete($k);
        }
    }

    return (bool)$result;
}

  private function GETSUFIX($fileType) {
    $sufixMap = [
        "image/jpg" => ".jpg",
        "image/jpeg" => ".jpg",
        "image/gif" => ".gif",
        "image/png" => ".png"
    ];

    return $sufixMap[$fileType] ?? false;
}


   


    

}

?>
