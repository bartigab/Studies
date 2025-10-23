<?php

class MyCaptcha {
    public $code = "";
    public $fontList = [];
    private $rotation = 50;
    private $width = 200;
    private $height = 50;

    function __construct() {
        if (isset($_SESSION["mycaptcha"]))
        {
            $this->code = $_SESSION["mycaptcha"];
        }
        
        $this->fontList = [
            'fonts/arial.ttf',
            'fonts/hemihead.ttf',
            'fonts/leadcoat.ttf',
            'fonts/stocky.ttf',
            'fonts/stormfaze.ttf'
        ];
    }

    function generate() {
        $this->code = join(array_map(function() {
            return chr(random_int(ord('A'), ord('Z')));
        }, range(1, 4)));
        $_SESSION["mycaptcha"] = $this->code;
    }

    function showCaptcha() {
        $this->generate();
        $image = imagecreatetruecolor($this->width, $this->height);
        $color = imagecolorallocate($image, 0, 0, 0);
        imagecolortransparent($image, $color);

        foreach (str_split($this->code) as $i => $char) {
            $color = imagecolorallocate($image, 150, 150, 150);
            imagettftext(
                $image, 
                random_int(22, 25), 
                random_int(-$this->rotation, $this->rotation),
                10 + ($i * ($this->width / 4)), 
                35,
                $color, 
                $this->fontList[array_rand($this->fontList)], 
                $char
            );
        }

        header('Content-Type: image/png');
        imagepng($image);
        imagedestroy($image);
        die();
    }

    function checkCaptcha($input) {
        return $input === $this->code;
    }
}

