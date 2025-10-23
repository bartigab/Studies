<?php

    function get_data() {
        if (!file_exists("data.json"))
            file_put_contents("data.json", json_encode(array('threads'=>array(), 'last_update'=>null), JSON_PRETTY_PRINT));
        return json_decode(file_get_contents("data.json"), true);
    }


    function save_data(&$data) {
        file_put_contents("data.json", json_encode($data, JSON_PRETTY_PRINT));
    }

    //getting tthreads by id
    function get_thread(&$data, $id) {
        foreach ($data['threads'] as $thread) {
            if ($thread['id'] == $id)
                return $thread;
        }
        return null;
    }
    
    // add a new thread
    function add_thread(&$data, $title, $author, $content) {
        $new_thread = [
            'id' => count($data['threads']) ? (int)end($data['threads'])['id'] + 1 : 1,
            'title' => htmlspecialchars($title),
            'author' => htmlspecialchars($author),
            'description' => str_replace("\r\n", "<br />", htmlspecialchars($content)),
            'date' => date('Y-m-d H:i:s'),
            'posts' => []
        ];
        $data['threads'][] = $new_thread;
        set_last_update($data);
        save_data($data);
    }

    //editting
    function edit_thread(&$data, $id, $title, $author, $content) {
        foreach ($data['threads'] as $key => $thread) {
            if ($thread['id'] == $id) {
                $thread['title'] = htmlspecialchars($title);
                $thread['author'] = htmlspecialchars($author);
                $thread['description'] = str_replace("\r\n", "<br />", htmlspecialchars($content));
                $thread['date'] = date('Y-m-d H:i:s');
                $data['threads'][$key] = $thread;
                set_last_update($data);
                save_data($data);
            }
        }
    }

    //delete
    function delete_thread(&$data, $id) {
        foreach ($data['threads'] as $key => $thread) {
            if ($thread['id'] == $id) {
                array_splice($data['threads'], $key, 1);
                save_data($data);
            }
        }
    }

    // get ids of threads that are before and after the given post
    function get_thread_nearests_ids($data, $thread_id) {
        $threads_ids = array_column($data['threads'], 'id');
        $index = array_search($thread_id, $threads_ids);
        $prev_id = $index > 0 ? $threads_ids[$index-1] : null;
        $next_id = $index < count($threads_ids)-1 ? $threads_ids[$index+1] : null;
        return [$prev_id, $next_id];
    }

    // get post by id
    function get_post($thread, $id) {
        foreach ($thread['posts'] as $post) {
            if ($post['id'] == $id)
                return $post;
        }
        return null;
    }

    // add a new post to a thread
    function add_post(&$data, $thread_id, $author, $content) {
        $thread = get_thread($data, $thread_id);
        if ($thread) {
            $new_post = [
                'id' => count($thread['posts']) ? (int)end($thread['posts'])['id'] + 1 : 1,
                'author' => htmlspecialchars($author),
                'content' => str_replace("\r\n", "<br />", htmlspecialchars($content)),
                'date' => date('Y-m-d H:i:s')
            ];
            $data['threads'][array_search($thread, $data['threads'])]['posts'][] = $new_post;
            set_last_update($data);
            save_data($data);
        }
    }

    // edit a post
    function edit_post(&$data, $thread_id, $post_id, $author, $content) {
        $thread = get_thread($data, $thread_id);
        if ($thread) {
            foreach ($thread['posts'] as $key => $post) {
                if ($post['id'] == $post_id) {
                    $post['author'] = htmlspecialchars($author);
                    $post['content'] = str_replace("\r\n", "<br />", htmlspecialchars($content));
                    $post['date'] = date('Y-m-d H:i:s');
                    $data['threads'][array_search($thread, $data['threads'])]['posts'][$key] = $post;
                    set_last_update($data);
                    save_data($data);
                }
            }
        }
    }

    // delete a post
    function delete_post(&$data, $thread_id, $post_id) {
        $thread = get_thread($data, $thread_id);
        if ($thread) {
            foreach ($thread['posts'] as $key => $post) {
                if ($post['id'] == $post_id) {
                    array_splice($data['threads'][array_search($thread, $data['threads'])]['posts'], $key, 1);
                    save_data($data);
                }
            }
        }
    }

    // set last update date on the forum
    function set_last_update(&$data) {
        $data['last_update'] = date('Y-m-d H:i:s');
    }

    // get last update date on the forum
    function get_last_update($data) {
        $last_update = $data['last_update'] ? $data['last_update'] : 'N/A';
        return $last_update;
    }
?>