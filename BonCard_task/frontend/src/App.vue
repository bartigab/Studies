<template>
  <div class="page">
    <NavBar />
    <main class="center-wrap">
      <div class="card-surface">
        <router-view />
      </div>
    </main>
  </div>
</template>


<script setup>
import NavBar from './components/NavBar.vue'
</script>

